//
//  NTMPoint.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NTMPoint : NSObject

@property(nonatomic) double x;
@property(nonatomic) double y;
@property(nonatomic) double rms;
@property(nonatomic) double accuracy;
@property(nonatomic) float orientation;
@property(nonatomic) bool isEigenSector;
@property(nonatomic) int mapId;

@end
