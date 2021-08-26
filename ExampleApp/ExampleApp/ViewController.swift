//
//  ViewController.swift
//  ExampleApp
//
//  Created by Francesco Paolo Dellaquila on 19/09/2020.
//  Copyright © 2020 Nextome. All rights reserved.
//

import UIKit
import Flutter
import PhoenixSdk
import PKHUD
import Toast_Swift

class ViewController: UIViewController {

    //UI
    @IBOutlet weak var startSdkButton: UIButton!
    @IBOutlet weak var openMapButton: UIBarButtonItem!
    
    //nextome sdk
    var sdk: NextomeSdk?
    
    //flutter map
    var flutterViewController: FlutterViewController?
    var flutterEngine = (UIApplication.shared.delegate as? AppDelegate)?.flutterEngine
    var mapChannel = FlutterMethodChannel()
    
    //controller data
    var start = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //MARK: Init flutter channel and controller
        flutterViewController = FlutterViewController(engine: flutterEngine!, nibName: nil, bundle: nil)
        self.mapChannel = FlutterMethodChannel(name: "net.nextome.phoenix", binaryMessenger: flutterViewController!.binaryMessenger)
        
        //MARK: add Nextome observers
        //position observer
        NotificationCenter.default.addObserver(self, selector: #selector(onDidReceivePosition(_:)), name: NSNotification.Name(rawValue: "POSITION_STREAM"), object: nil)
            
        //position observer
        NotificationCenter.default.addObserver(self, selector: #selector(onDidReceiveFloorChange(_:)), name: NSNotification.Name(rawValue: "FLOOR_CHANGE"), object: nil)
        
        //refresh POI observer
        NotificationCenter.default.addObserver(self, selector: #selector(onRefreshPoiComplete(_:)), name: NSNotification.Name(rawValue: "REFRESHPOI_COMPLETE"), object: nil)

        //outdoor observer
        NotificationCenter.default.addObserver(self, selector: #selector(onDidReceiveOutdoor(_:)), name: NSNotification.Name(rawValue: "OUTDOOR_STREAM"), object: nil)
        
        //log observer
        NotificationCenter.default.addObserver(self, selector: #selector(onDidReceiveLogs(_:)), name: NSNotification.Name(rawValue: "LOG_WRITER"), object: nil)
            
        //error observer
        NotificationCenter.default.addObserver(self, selector: #selector(onDidReceiveError(_:)), name: NSNotification.Name(rawValue: "ERROR"), object: nil)
        
        //nextome sdk
        self.sdk = (UIApplication.shared.delegate as? AppDelegate)?.sdk
        
        //MARK: disable open map button: ONLY FOR SIMULATOR
        //self.openMapButton.isEnabled = false
        //self.openMapButton.tintColor = .gray
        //self.openMapButton.customView?.isUserInteractionEnabled = false
    
    }

    
    //MARK: FLoor observer
    @objc func onDidReceiveFloorChange(_ notification: Notification){
        //receive position
        let floorData = notification.userInfo as? [String : [String: Any]]
        
        //advise ui
        PKHUD.sharedHUD.contentView = PKHUDTextView(text: "Floor is changed: \(floorData!["floorData"]!["floor"] as! Int)")
        PKHUD.sharedHUD.show()
        PKHUD.sharedHUD.hide(afterDelay: 1.0) { success in
        }
        
        //update package
        let data = self.sdk?.getVenueData()
        mapChannel.invokeMethod("localPackageUrl", arguments: data)
        
        //update poi
        let poiData = self.sdk?.getPOIData()
        mapChannel.invokeMethod("POI", arguments: poiData)
        
    }
    
    @objc func onRefreshPoiComplete(_ notification: Notification){
        //update poi
        let poiData = self.sdk?.getPOIData()
        mapChannel.invokeMethod("POI", arguments: poiData)
    }
    
    //MARK: MAP Position observer
    @objc func onDidReceivePosition(_ notification: Notification){
        
        
        //receive position
        let positionData = notification.userInfo as? [String : [String: Any]]
        
        //enableButton
        self.openMapButton.isEnabled = true
        self.openMapButton.tintColor = .systemBlue
        self.openMapButton.customView?.isUserInteractionEnabled = true
        
        //map update
        let x = positionData!["positionData"]!["x"] as! String
        let y = positionData!["positionData"]!["y"] as! String
        let floor = positionData!["positionData"]!["floor"] as! String
        
        self.mapChannel.invokeMethod("position", arguments: x + "," + y)

    }
    
    //MARK: Outdoor stream
    @objc func onDidReceiveOutdoor(_ notification: Notification){
        
        //receive position
        let positionData = notification.userInfo as? [String : Double]
        
        let lat = positionData!["lat"]!
        let lng = positionData!["lng"]!
        
        //advise ui
        PKHUD.sharedHUD.contentView = PKHUDTextView(text: "Your are currently outdoor. SDK are searching nearby venue...")
        PKHUD.sharedHUD.show()
        PKHUD.sharedHUD.dimsBackground = false
        PKHUD.sharedHUD.hide(afterDelay: 1.5) { success in
        }
        
        //LOG WRITER
        print("SDK Outdoor -> lat: \(lat) \n lng: \(lng)")
        //MARK: LOG STREAM
        NotificationCenter.default.post(name: Notification.Name("LOG_WRITER"), object: nil, userInfo: ["log": "Outdoor -> lat: \(lat) \n lng: \(lng)"])
    }
    
    //MARK: MAP Path observer
    @objc func onDidReceivePath(_ notification: Notification){
        
        //receive path
        let pathData = notification.userInfo as? [String : String]
        
        if(pathData!["pathData"] != nil){
            if(pathData!["pathData"] == "[]"){
                //advise ui
                PKHUD.sharedHUD.contentView = PKHUDTextView(text: "Shortest path not found. Please try again")
                PKHUD.sharedHUD.show()
                PKHUD.sharedHUD.dimsBackground = false
                PKHUD.sharedHUD.hide(afterDelay: 2) { success in
                }
            }else{
                self.mapChannel.invokeMethod("path", arguments: pathData!["pathData"]!)
            }
            
        }
    }
    
    //MARK: Error observer
    @objc func onDidReceiveError(_ notification: Notification){
        
        self.sdk?.stop()
        
        //receive position
        let error = notification.userInfo as? [String : String]
        
        //advise ui
        PKHUD.sharedHUD.contentView = PKHUDTextView(text: "Error: \(error!["error"] ?? ""). Please restart sdk")
        PKHUD.sharedHUD.show()
        PKHUD.sharedHUD.hide(afterDelay: 1.0) { success in
        }

    }
    
    //MARK: LOGS Observer
    @objc func onDidReceiveLogs(_ notification: Notification){
        //receive logged
        let logInfo = notification.userInfo as? [String: String]
        let log = logInfo!["log"]!
        
        print("------LOG: \(log)")
    }

    @IBAction func startSdk(_ sender: Any) {
        self.start = !self.start
        if(self.start){
            self.sdk!.start()
            
            //change start text
            self.startSdkButton.setTitle("Stop", for: UIControl.State.normal)
            
        }else{
            self.sdk!.stop()
            
            //change start text
            self.startSdkButton.setTitle("Start", for: UIControl.State.normal)
        }
    }
    
    @IBAction func openMap(_ sender: Any) {
        
        //MARK: RESET PATH BUTTON
        /*//add menu icon
        //create a new button
        let button: UIButton = UIButton(type: UIButton.ButtonType.custom)
        button.setTitle("Reset Path", for: .normal)
        button.backgroundColor = .blue
        //add function for button
        button.addTarget(self, action:  #selector(self.resetPath(_:)), for: UIControl.Event.touchUpInside)
        //set frame
        button.frame = CGRect(x: 0, y: 0, width: 53, height: 31)

        let barButton = UIBarButtonItem(customView: button)
        //assign left menu button to navigationbar
        flutterViewController!.navigationItem.rightBarButtonItem = barButton*/
        
        //MARK: SWITCH MAP BUTTON
        //add menu icon
        //create a new button
        let button: UIButton = UIButton(type: UIButton.ButtonType.custom)
        button.setTitle("Switch map", for: .normal)
        button.backgroundColor = .blue
        //add function for button
        button.addTarget(self, action:  #selector(self.refreshMap(_:)), for: UIControl.Event.touchUpInside)
        //set frame
        button.frame = CGRect(x: 0, y: 0, width: 53, height: 31)

        let barButton = UIBarButtonItem(customView: button)
        //assign left menu button to navigationbar
        flutterViewController!.navigationItem.rightBarButtonItem = barButton
        
        //push flutter controller
        self.navigationController?.pushViewController(flutterViewController!, animated: true)

        //show POI
        let poiData = self.sdk?.getPOIData()
        mapChannel.invokeMethod("POI", arguments: poiData)
         
        //show mapview
        let data = self.sdk?.getVenueData()
        mapChannel.invokeMethod("localPackageUrl", arguments: data)
        
        //flutter callbacks
        mapChannel.setMethodCallHandler{(call: FlutterMethodCall, result: FlutterResult) -> Void in
            // Handle poi json
            if call.method == "poiData"{
                
                //calculate path
                self.sdk?.calculatePath_ToPOI(poi: call.arguments as? String)
            }
            
            // Handle long press
            if(call.method == "customPosition"){
                let customPosition = call.arguments as! String
                
                //advise user
                if(self.sdk?.customPositionCheck == 0){
                    //advise ui
                    PKHUD.sharedHUD.contentView = PKHUDTextView(text: "Start point is set")
                    PKHUD.sharedHUD.show()
                    PKHUD.sharedHUD.hide(afterDelay: 1.0) { success in
                    }
                }
                
                self.sdk?.calculatePath_ToCustomPoint(point: customPosition)

            }
        }
    }
    
    //MARK: clear calculated path
    @objc func resetPath(_ sender:UITapGestureRecognizer) {
        
        //reset sdk poi
        self.sdk?.calculatePath_ToPOI(poi: nil)
        
        //reset map path
        self.mapChannel.invokeMethod("path", arguments: "[]")
        
        //This method will call when you press button.
        self.flutterViewController!.view.makeToast("Path reset complete", duration: 3.0, position: .bottom)
    }
    
    
    //MARK: choose map dialog
    @objc func refreshMap(_ sender:UITapGestureRecognizer) {
        
        let alert = UIAlertController(title: "Change Map", message: "Choose map id", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "696", style: .default, handler: { action in
            self.sdk?.forceRefreshMap(mapId: 696)
        }))
        
        alert.addAction(UIAlertAction(title: "686", style: .default, handler: { action in
            self.sdk?.forceRefreshMap(mapId: 686)
        }))
        self.present(alert, animated: true, completion: nil)
    }
}


