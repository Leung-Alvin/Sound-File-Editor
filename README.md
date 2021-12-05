# CS-202-Semester-Project
This is a basic level project
Created by Alvin Leung, Carissa Schwartz, and Wes Bovee
    Alvin Leung performed: Programming of the WAV header, file intake, and WAV class
    Carissa Schwartz performed: Doxygen implementation, documentation, and file cleanup
    Wes Bovee performed: Programming of the UI class and processors
UML diagram:
Issues: WARNING: Though the project generally works for 16-bit-mono data. 8-bit and/or stereo data appears to be corrupted and high volume noise outputs. This is also true for stereo input. I would lower your volume before listening to 8-bit data and stereo. The echo processor works with all data generally, but the gain adjustment and normalization processors appear to not work well, though were attempted.
Challenges: Our group had difficulty communicating with each other during the beginning of the project. Beyond that, there was the usual difficulty that accompanies a hard programming assignment.
Instructions beyond 'make': Make sure you have a WAV files stored in the same folder as the one that the UI.cpp and UI.h is saved in. Make sure you do not write ".wav" after your file, as the program looks for with just the base name.
