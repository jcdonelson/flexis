rmdir /S /Q FWProjects
"C:\Program Files\7-Zip\7z.exe" x -oFWProjects FWProjects.zip
"C:\Program Files (x86)\Freescale\CW MCU v10.1\eclipse\ecd" -build -data K:\release\FWProjects\WS_SAMPLES -project k:\release\fwprojects\ws_samples\BLINK_FB32
"C:\Program Files (x86)\Freescale\CW MCU v10.1\eclipse\cwide.exe" -data k:/release/FWProjects/WS_SAMPLES