In order to use this program you will need to download SFML if you do not already have SFML installed.
    - This is a link to the SFML website for the instalation: https://www.sfml-dev.org/download/sfml/2.6.2/

If You are using Visual Studios you will want to follow the following steps;
  - Create an empty project
  - Go into the project properties and then into the configuration properties
  -     From there change the "Platform" on both "Release" and "Debug" to "Win32"
  - Click on the C/C++ tab in project properties(If you do not see a "C/C++" tab then exit project properties, click on the solution in your project window and then click on project properties once again)
  -     Click on the "General" tab and in the "Aditional Dependencies" input the path to the "include" file that is in the SFML file you downloaded.
  - Click on the Linker Tab in project properties( If you do not see a "Linker" tab then exit project properties, click on the solution in your project window and then click on project properties once again)
  -     In Linker you will want to click on the "General" tab and input the path to the "lib" file in the SFML file you downloaded.
  -     In Linker you will want to click on the "Input" tab and input the following when your "Configuration" is set to "Debug"
  -         sfml-graphics-d.lib;sfml-system-d.lib;sfml-audio-d.lib;sfml-window-d.lib;sfml-network-d.lib;%(AdditionalDependencies)
  -     In Linker you will want to click on the "Input" tab and input the following when your "Configuration" is set to "Release"
  -         sfml-graphics.lib;sfml-system.lib;sfml-audio.lib;sfml-window.lib;sfml-network.lib;%(AdditionalDependencies)
The program should now work with your visual studios.
