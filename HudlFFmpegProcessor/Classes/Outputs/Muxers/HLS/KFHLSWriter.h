//
//  KFHLSWriter.h
//  FFmpegEncoder
//
//  Created by Christopher Ballinger on 12/16/13.
//  Copyright (c) 2013 Christopher Ballinger. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface KFHLSWriter : NSObject

@property (nonatomic, copy, readonly) NSString *manifestPath;
@property (nonatomic) dispatch_queue_t conversionQueue;

- (id) initWithDirectoryPath:(NSString*)directoryPath segmentCount:(NSUInteger)segmentCount;

- (void) addVideoStreamWithWidth:(int)width height:(int)height;
- (void) addAudioStreamWithSampleRate:(int)sampleRate;

- (BOOL) prepareForWriting:(NSError**)error;

- (void) processEncodedData:(NSData*)data presentationTimestamp:(CMTime)pts streamIndex:(NSUInteger)streamIndex isKeyFrame:(BOOL)isKeyFrame; // TODO refactor this

- (BOOL) finishWriting:(NSError**)error;

@end