//
//  NTMRegistrationSupervisor.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 20/09/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMConfig.h"

@class NTMBootstrap;

@interface NTMBootstrap : NSObject{
    
    BOOL progressGpsVenue;
}

- (void)startScanningForGpsLocation;
- (void)stopNotificationsForPackage;


-(void)startPathfindingToX:(double) toX andToY:(double) toY andDestinationMap:(int) destinationMapId andPoiId:(int) poiId;
-(void)stopPathFinding;
-(void)stopClient;
-(void)startSearchForText:(NSString*) textSearch andMapId:(int) mapId;
-(void)startPoiVisualization:(int) poiId;
-(void)startLoginProcedure:(NSString*) email andMac:(NSString*) mac andName:(NSString* )name andGender:(NSString*) gender andSource:(NSString*) source andUserId:(NSString*) userId andPhotoUrl:(NSString*) photoUrl andBirthday:(NSString*) birthday andLocation:(NSString*) location;
-(NSArray*)getOutdoorPoisFromJson;
-(NTMConfig*)getConfig;


@end
