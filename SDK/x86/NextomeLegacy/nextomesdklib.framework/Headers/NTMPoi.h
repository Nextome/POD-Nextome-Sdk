//
//  NTMPoi.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 01/02/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMPoi : NSObject

@property(nonatomic) int idPoi;
@property(nonatomic,strong) NSString *descriptionPoi;
@property(nonatomic,strong) NSString *image;
@property(nonatomic) int idMarker;
@property(nonatomic,strong) NSString *namePoi;
@property(nonatomic) int idRoom;
@property(nonatomic) int category;
@property(nonatomic,strong) NSNumber *lat;
@property(nonatomic,strong) NSNumber *lon;
@property(nonatomic,strong)NSString *uuid;
@property(nonatomic)int major;
@property(nonatomic)int minor;


+(NTMPoi *) NTMPoiWithId:(int) idPoi andDescription:(NSString*) descriptionPoi andImage:(NSString *) imagePoi andName:(NSString *) namePoi andMarker:(int) markerPoi andRoom:(int) roomPoi andCategory:(int) categoryPoi;

-(id)initWithId:(int) idPoiObj andDescription:(NSString *) descriptionPoiObj andImage:(NSString *) imagePoiObj andName:(NSString *) namePoiObj andMarker:(int) markerPoiObj andRoom:(int) roomPoiObj andCategory:(int) categoryPoiObj;
@end
