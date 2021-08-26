//
//  NMMapView.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 29/05/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import "NMMapPath.h"
#import "NMMapAnnotation.h"
#import "NMMapAnnotationView.h"
#import <UIKit/UIKit.h>


@class NMMapView;

@protocol NMMapViewDelegate <NSObject>

@optional
- (NMMapAnnotationView *)indoorMapView:(NMMapView *)mapView viewForAnnotation:(id <NMMapAnnotation>)annotation;
- (void)indoorMapView:(NMMapView *)mapView didSelectAnnotationView:(NMMapAnnotationView *)view;
- (void)indoorMapView:(NMMapView*)mapView calloutRightAccessoryControlTappedWithAnnotation:(id <NMMapAnnotation> )annotation;
- (void)indoorMapView:(NMMapView *)mapView mapTouchedWithNoPois:(BOOL) noPois;
- (void)indoorMapView:(NMMapView *)mapView withPois:(NSArray*) pois;
@end


@interface NMMapView : UIView

@property (nonatomic, getter=isRotateEnabled) BOOL rotateEnabled;
@property (nonatomic, assign) CGFloat north;

@property (assign) id <NMMapViewDelegate> delegate;
@property (nonatomic, readonly) NSArray *annotations;



- (void)setMapImage:(UIImage*)mapImage withMarkers:(NSArray *) markers andPois:(NSArray *) pois andDelegate:(id<NMMapViewDelegate>) delegate;

- (void)drawPath:(NMMapPath*)path;
- (void)removeAllPaths;

- (CGPoint)userPosition;
- (void)setUserPosition:(CGPoint)userPosition;
- (void)setUserPosition:(CGPoint)userPosition animated:(BOOL)animated;

- (void)setUserError:(CGFloat)errorInPixels;
- (void)setUserErrorModeEnabled:(BOOL)enabled;
- (void)createUIElementsWithFrame:(CGRect)frame;



@end
