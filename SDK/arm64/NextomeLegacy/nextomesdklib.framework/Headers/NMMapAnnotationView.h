//
//  NMMapAnnotationView.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 30/05/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import "NMMapAnnotation.h"

#import <UIKit/UIKit.h>

@interface NMMapAnnotationView : UIView

@property (nonatomic, readonly) NSString *reuseIdentifier;

@property (nonatomic, strong) id <NMMapAnnotation> annotation;
@property (nonatomic) CGPoint anchorPoint;
@property (nonatomic) CGPoint calloutOffset;
@property (nonatomic) BOOL canShowCallout;

@property (nonatomic, strong) UIImage *image;

@property (strong, nonatomic) UIView *leftCalloutAccessoryView;
@property (strong, nonatomic) UIView *rightCalloutAccessoryView;

- (id)initWithAnnotation:(id<NMMapAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;


@end
