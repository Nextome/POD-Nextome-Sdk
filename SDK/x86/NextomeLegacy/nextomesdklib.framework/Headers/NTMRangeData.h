//
//  NTMRangeData.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 03/08/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/*!
 Container class for data associated with ranging behaviour
 Allows range data to be packaged and passed around easily.
 Implements the NSCoding protocol so that it can be used in conjunction with NTMSerialisedDictionary.
 Can be used with geofences as well as beacons.
 */
@interface NTMRangeData : NSObject<NSCopying> {
    
    NSMutableArray *_accuracyHistory;
    NSMutableArray *_rssiHistory;
}

@property (nonatomic, strong) NSString *identifier;
@property(nonatomic) int idBeacon;

@property (nonatomic, readonly) CLProximity bestProximity;
@property (nonatomic, readonly) CLLocationAccuracy bestAccuracy;
@property (nonatomic) long int rssi;
@property (nonatomic) long int previousRssi;
@property (nonatomic)  double accuracy;
@property (nonatomic)  double previousAccuracy;
@property(nonatomic) float x;
@property(nonatomic) float y;


- (void)setProximity:(CLProximity)proximity;
- (void)setAccuracy:(CLLocationAccuracy)accuracy;
- (void)setRssi:(long)rssi;


@end
