//
//  nextomesdk.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 02/08/2015.
//  Copyright (c) 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMGlobal.h"
#import "NTMBackgroundProtocol.h"
#import "NTMBootstrap.h"
#import "NTMLogToFileWriter.h"
#import "NTMConfig.h"


@protocol NTMManagerDelegate <NSObject>

@optional

-(void)didReceiveMapForVenue:(NSString *)mapFile andMarkers:(NSArray*)markers andPois:(NSArray *) pois andGlobalPois:(NSArray *) globalPois andGlobalMarkers:(NSArray *) globalMarkers andPrefixVenue:(NSString *) prefixVenueDirectory andIdMap:(NSNumber *) idMap;
-(void)didReceivePositionInVenue:(NSNumber *)currentX andCurrentY:(NSNumber *) currentY;
-(void)didReceivePathInVenue:(NSArray *)points;
-(void)didReceiveNtmError:(NSError *)error;
-(void)didExitCurrentVenueWithId:(NSNumber *)idVenue;
-(void)didReceiveEventZones:(NSArray *) eventZones;
-(void)didEnterVenueWithId:(NSNumber*) idVenue;
-(void)didReceiveGpsPositionWithLatitude:(NSNumber*) lat andLongitude:(NSNumber*) lon;
-(void)didReceiveOutdoorPois:(NSArray *) pois;




@end


@interface NTMManager : NSObject{
}

@property (nonatomic, assign) id <NTMManagerDelegate> ntmDelegate;

@property(nonatomic,strong) NTMBootstrap *bootstrap;

- (void)setupClient;
- (void)setupClientWithRealTimePositionInterval:(int)realTimePositionInterval;
- (void)shutdown;
-(void)startPathFindingForDestination:(double) toX andToY:(double) toY andDestinationMap:(int) destinationMapId andPoiId:(int) poiId;
-(void)startScanningForLocation;
-(void)stopPathFinding;
-(void)startSearchForText:(NSString*) textSearch andMapId:(int) mapId;
-(void)startPoiVisualization:(int) poiId;
-(void)startLoginProcedure:(NSString*) email andMac:(NSString*) mac andName:(NSString* )name andGender:(NSString*) gender andSource:(NSString*) source andUserId:(NSString*) userId andPhotoUrl:(NSString*) photoUrl andBirthday:(NSString*) birthday andLocation:(NSString*) location;
-(void)startLogoutProcedure;
-(NSArray*)getOutdoorPoisDirect;
- (void)stopClient;
-(NTMConfig*) getSharedConfig;




/*
 email: string - l'email dell'utente
 mac: string - il mac della scheda wifi
 name: string - il nome dell'utente (social)
 gender: string - il sesso dell'utente (social)
 source: string - la sorgente de dati personali. Un valore tra 'fb' e 'google'
 userid: string - se la sorgente è settata, salva Facebook id o Google id
 photo: string - l'url della foto pubblica dell'utente (social)
 birthday: string - Data di nascita nel formato MM/dd/yyyy (social)
 location: string - Indirizzo dell'utente (social)
 guest mode : solo mail e mac
 
 
 */


@end
