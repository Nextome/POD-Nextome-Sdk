//
//  NonLinear.h
//  Group5iBeacons
//
//  Created by Nemanja Joksovic on 6/11/14.
//  Copyright (c) 2014 John Tubert. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NTMLocation.h"
#import "NTMRangeData.h"
#import "NTMMathHelper.h"

@interface NonLinear : NSObject

+ (NTMLocation *)determine:(NSArray *)transmissions;

@end
