//
//  NTMMathHelper.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 30/12/15.
//  Copyright © 2015 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMMathConstants.h"
#import "NTMLocation.h"
#import "NonLinear.h"
#import "NTMRangeData.h"
#import "NTMLogToFileWriter.h"
#import "NTMDijkstraGraph.h"
#import "NTMNewtonHelper.h"


@interface NTMMathHelper : NSObject

+(double) calculateEma:(double) currentValue andPreviousValue:(double) previousValue;
+(NTMLocation * ) calculatePositionWithBeacons:(NSDictionary *) currentRangeData withGraph:(NTMDijkstraGraph*) graph andEnableBinaries:(BOOL) enableBinaries;
@end
