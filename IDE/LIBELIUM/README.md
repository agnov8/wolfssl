### wolfSSL with Libelium

##### Reformatting wolfSSL folder structure for compatibility w/ Libelium's folders

This is a shell script that will re-organize the wolfSSL library to be 
compatible with Libelium (*.pde) projects. The Libelium IDE requires a library's source
files to be in the library's root directory with a header file in the name of 
the library. This script moves all src/ files to a temporary libelium directory in the 
the wolfssl project called 'wolfssl-libelium' and creates a stub header file called wolfssl.h.

To configure wolfSSL w/ Libelium, enter the following from within the wolfssl/IDE/LIBELIUM directory:

    ./wolfssl-libelium.sh
    
##### Including wolfSSL in Libelium Libraries (for Libelium API v22+)
1. Link the 'wolfssl-libelium' folder to a folder (e.g. 'WolfSSL') within the <libelium-project>/libraries folder
2. In your libelium IDE:
    - Go to ```Sketch > Include Libraries > Manage Libraries```. This refreshes your changes to the libraries.
    - Next go to ```Sketch > Include Libraries > WolfSSL```. This includes WolfSSL in your sketch.
