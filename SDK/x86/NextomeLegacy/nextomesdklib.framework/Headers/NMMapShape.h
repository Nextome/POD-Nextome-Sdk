//
//  NMMapShape.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 05/06/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import "NMMapAnnotation.h"
#import <Foundation/Foundation.h>

@interface NMMapShape : NSObject <NMMapAnnotation>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;

@end
