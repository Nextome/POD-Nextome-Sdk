//
//  NTMMarker.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 23/12/15.
//  Copyright © 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMMarker : NSObject

@property(nonatomic)int idMarker;
@property(nonatomic)int map;
@property(nonatomic)int poi;
@property(nonatomic)double x;
@property(nonatomic)double y;

+(NTMMarker *) NTMMarkerWithId:(int) idMarker andMap:(int) map andPoi:(int) poi andX:(double) x andY:(double) y;

-(id)initWithId:(int)idMarkerObj andMap:(int) mapObj andPoi:(int) poiObj andX:(int)xObj andY:(int)yObj;




@end
