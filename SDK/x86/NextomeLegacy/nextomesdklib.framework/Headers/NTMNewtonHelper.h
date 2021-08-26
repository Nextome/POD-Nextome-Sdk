//
//  NTMNewtonHelper.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 30/12/15.
//  Copyright © 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMRangeData.h"
#import "NTMLocation.h"

@interface NTMNewtonHelper : NSObject

+(NTMLocation * ) calculateNewtonWithBeacons:(NSArray *) beacons ;
+(float) getWeightFromProximity:(CLProximity) proximity;
+(float) map:(long) x inMin:(long)in_min inMax:(long) in_max outMin:(long)out_min outMax:(long) out_max;
+(float) getWeightFromRssi:(long) rssi WithMaxRssi:(long) maxRssi AndMinRssi:(long) minRssi;




@end
