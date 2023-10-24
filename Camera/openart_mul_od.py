import sensor, image, time, gc
import KPU as kpu

sensor.reset()                      # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565) # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)   # Set frame size to QVGA (320x240)
sensor.skip_frames(time = 2000)     # Wait for settings to take effect.
clock = time.clock()                # Create a clock object to track the FPS.

# Load the KModel (converted from TensorFlow Lite model)
kmodel_path = '/sd/yolo3_iou_smartcar_final_with_post_processing.kmodel'
task = kpu.load(kmodel_path)

while True:
    clock.tick()
    img = sensor.snapshot()

    # Run inference with the loaded KModel
    code = kpu.run(task, img)
    if code:
        print("KPU error: " + str(code))
        continue

    # Get the detected objects
    objs = kpu.rect(task)
    if objs:
        for obj in objs:
            x, y, w, h, score = obj.rect()

            if score > 0.70:
                print(obj)
                x1 = int(x)
                y1 = int(y)
                w = int(w)
                h = int(h)
                img.draw_rectangle((x1, y1, w, h), thickness=2)

    print(clock.fps())
