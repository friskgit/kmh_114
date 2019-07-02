::: {#content}
::: {#outline-container-org4f31450 .outline-2}
General information {#org4f31450}
-------------------

::: {#text-org4f31450 .outline-text-2}
:::

::: {#outline-container-org3f7884d .outline-3}
### []{#org3f7884d}Ambisonics in KMH studios and Lilla salen {#github:readme_template}

::: {#text-github:readme_template .outline-text-3}
:::

::: {#outline-container-org7c77067 .outline-4}
#### About the compiled decoders {#org7c77067}

::: {#text-org7c77067 .outline-text-4}
All decoders use ACN channel order (see [Component order](#orgbce8f6b))
and SN3D normalization (see [Normalisation](#org437c845)) and are
dual-band, max-rE/rV.
:::

-   []{#org731cae9}A guide to the file names\
    ::: {#text-org731cae9 .outline-text-5}
    For efficiency file names are composed of the following parts

    1.  The space (for Lilla Salen this is KMHLS\_AE)
    2.  Speaker configuration (Full or Normal where the former in
        108/118 and 114 means the center speaker is included, and in
        Lilla Salen it refers to the 45.4 setup)
    3.  Order (e.g. 7H7P)
    4.  Redundant speaker configuration (full, but only in certain cases
        for Lilla Salen)
    5.  Finally, a number depicting the type of decoder according to the
        following codes:
    :::

    -   []{#org53b3ff8}(1) AllRad mixed order (4/3)\
        ::: {#text-org53b3ff8 .outline-text-6}
        Mixed order ambisonics decoder.
        :::

    -   []{#org96833e6}(2) Decoding with the pseudo-inverse,
        even-energy\
        ::: {#text-org96833e6 .outline-text-6}
        Pinv decoders in 1st, 3rd order with even-energy for inversion
        variants.

        The higher order decoders in pseudo-inverse do not work well, so
        do not try those above 3rd order.
        :::

    -   []{#org8a43c66}(3) Decoding with the pseudo-inverse,
        mode-matching\
        ::: {#text-org8a43c66 .outline-text-6}
        Pinv decoders in 1st, 3rd order, mode-matching for inversion
        variants. This has been removed from the repository.
        :::

    -   []{#orge8a85a7}(4) Same as (2) but with a blend coefficient for
        inversion variants (energy limited/mode matching 50%)\
        ::: {#text-orge8a85a7 .outline-text-6}
        1st and 3rd and 6th order.

        The higher order decoders in pseudo-inverse do not work well, so
        do not try those above 3rd order - though sixth order has
        provecd useful.
        :::

    -   []{#orgda242b6}(5) Spherical slepian decoders\
        ::: {#text-orgda242b6 .outline-text-6}
        SSF decoders in 1st, 3rd and 6th order (6th order is here only
        as VST, but I can compile the other formats if needed.)
        :::

    -   []{#org865159c}(6) All-round decoders\
        ::: {#text-org865159c .outline-text-6}
        AllRAD decoders in 1st, 3rd, 5th and 7th order.
        :::

-   []{#org3d2d3bf}Ouput formats\
    ::: {#text-org3d2d3bf .outline-text-5}
    In the directory of each decoder there are four subdirectories:

    -   ambix: contains the decoder matrix for the ambix VST-plugin for
        certain settings.
    -   bin: contains all other decoders
    -   doc: documentation, a bare minimal (but a more comprehensive
        documentation can be built from the source, check the individual
        Makefiles for each compilere)
    -   src: the faust sources for the decoders

    The binaries are prepared in six different formats:

    1.  a jack application (start from commandline: \$
        KMHLS\_Dome\_4h3v\_normal\_1)
    2.  a double clickable CoreAudio application
    3.  a \'max\' directory with Max/MSP objects (as package with help
        files to be put in \~/Documents/Max 7/Packages)
    4.  a \'pd\' direcory (bang left most input to get parameter names)
    5.  a \'sc\' directory with SuperCollider classes (put all .sc and
        .scx in \~/Library/Application Support/SuperCollider/Extensions
        , the supernova files are of course optional)
    6.  an \'ambix\' directory with Ambix config file
    :::

    -   []{#org904876c}Install on your system\
        ::: {#text-org904876c .outline-text-6}
        You may simply move the decoders you want to use to the right
        locations on your system. They are compiled and ready to be used
        in the repository. As a convenience one may run the
        corresponding install scripts in the Makefile for the decoders
        to install them in your default directory:

        1.  Open a terminal (such as Terminal.app)
        2.  At the prompt type `$ cd` and drag one of the directories,
            say \'KMHLS\_AE\_normal\_6\' of your downloaded repository
            onto the terminal and press enter.
        3.  Enter `$ make maxinstall` at the prompt and press enter.

        The last step can be made for `scinstall`, `vstinstall` and
        `pdinstall`

        Note that to create a Max/MSP compatible package you may have to
        run maxinstall and have the reslevant dependencies resolved.
        Else, contact me!
        :::

-   []{#orgbce8f6b}Component order\
    ::: {#text-orgbce8f6b .outline-text-5}
    The component order for the input to the decoder follows the ACN
    (Ambisonics Channel Number) standard according to the table below
    (for third order):

      --- ---- ---- ---- ---- ---- ----
                    0               
               1    2    3          
          4    5    6    7    8     
      9   10   11   12   13   13   15
      --- ---- ---- ---- ---- ---- ----

    Or: W Y Z X V T R S U Q O M K L N P
    :::

-   []{#org437c845}Normalisation\
    ::: {#text-org437c845 .outline-text-5}
    The decoder is using SN3D normalisation. With SN3D normalisation no
    component will exceed the peak value of the 0th order component.
    :::

-   []{#orgb1572a0}Compiling the decoders\
    ::: {#text-orgb1572a0 .outline-text-5}
    This is only if you wish to tweak the settings in any way. All
    scripts needed for the compilation is in a speparate GitHub
    repository that may be found here: In order to compile the decoders
    there are a number of dependencies that need to be resolved:

    -   ADT (Ambisoncs Decoder Toolkit)
    -   Faust
    -   VST SDK
    -   Pure Data
    -   Max MSP SDK
    -   Links to Supercollider classes
    :::

    -   []{#orgbfe778f}Running Makefile scripts for ADT\
        ::: {#text-orgbfe778f .outline-text-6}
        Run the following for each function that needs to be compiled
        for lilla salen (108\_all and 114\_all for the studios):

        `$ make ls_all function=6`

        Note that for fuction 2 & 4 only orders up to 3 are usable.

        The decoding matrices end up in a directory above your current
        directory named \'decoders\'. Move into that directory with the
        following command:

        `$ cd ../decoders`

        With the decoding matrices calculated the binary decoders for
        all orders can be compiled by

        `$ make -k target=all all`

        The target can be either of \[all,sc,max,pd,vst\]. Following
        this step the binaries can be installed (to install only one
        target, use that as the argument for \'target\'.:

        `$ make -k target=install all`
        :::
:::
:::
:::

::: {#outline-container-org3e17267 .outline-2}
Studio 114 {#org3e17267}
----------

::: {#text-org3e17267 .outline-text-2}
:::

::: {#outline-container-org621e941 .outline-3}
### []{#org621e941}Specific info {#github:readme_ls}

::: {#text-github:readme_ls .outline-text-3}
:::

::: {#outline-container-orga3fa5c3 .outline-4}
#### Output {#orga3fa5c3}

::: {#text-orga3fa5c3 .outline-text-4}
In Klangkupolen the channel order from the mixer is channel 1-29 for the
regular dome. The lower ring starts at channel 33-48 and the subs are at
49-52. This is the reason that in the decoder the names for the sixteen
floor speakers start at 33.

The layout is ordered clockwise starting at speaker one.
:::
:::

::: {#outline-container-org4f79d33 .outline-4}
#### Speaker positions {#org4f79d33}

::: {#text-org4f79d33 .outline-text-4}
All distances and heigths are measured from 1.25m height from floor.

  ndx   azimuth      elevation   distance   radius
  ----- ------------ ----------- ---------- -----------
  1     -34.689614   12.910417   4.61       4.5789148
  2     -13.383763   12.910417   4.61       4.5577825
  3     10.440725    12.910417   4.61       4.5635592
  4     32.117788    12.910417   4.61       4.5386017
  5     55.741675    12.910417   4.61       4.4464181
  6     78.207673    12.910417   4.61       4.4723909
  7     101.49442    12.910417   4.61       4.4461719
  8     124.85167    12.910417   4.61       4.5148007
  9     147.91193    12.910417   4.61       4.5536496
  10    169.17789    12.910417   4.61       4.6069350
  11    -167.82013   12.910417   4.61       4.7018379
  12    -145.63454   12.910417   4.61       4.6822723
  13    -123.78400   12.910417   4.61       4.7368687
  14    -102.64182   12.910417   4.61       4.6743181
  15    -79.887731   12.910417   4.61       4.7101696
  16    -57.926139   12.910417   4.61       4.6119481
  17    -22.349553   34.696822   4.882      4.0761992
  18    22.843958    34.696822   4.882      3.7761827
  19    69.013292    34.696822   4.882      4.0485676
  20    115.56544    34.696822   4.882      4.1015729
  21    158.89992    34.696822   4.882      3.9444645
  22    -158.89763   34.696822   4.882      3.8051807
  23    -114.65354   34.696822   4.882      3.6199724
  24    -68.170128   34.696822   4.882      3.7380476
  25    -45.         69.185799   5.317      1.7225121
  26    45.          69.185799   5.317      1.7225121
  27    135.         69.185799   5.317      1.7225121
  28    -135.        69.185799   5.317      1.7225121
  29    0.           90.         5.576      0
  33    -8.439614    -3.089583   4.61       4.5789148
  34    -2.133763    -3.089583   4.61       4.5577825
  35    21.690725    -3.089583   4.61       4.5635592
  36    43.367788    -3.089583   4.61       4.5386017
  37    66.991675    -3.089583   4.61       4.4464181
  38    89.457673    -3.089583   4.61       4.4723909
  39    112.74442    -3.089583   4.61       4.4461719
  40    136.10167    -3.089583   4.61       4.5148007
  41    159.16193    -3.089583   4.61       4.5536496
  42    180.42789    -3.089583   4.61       4.6069350
  43    -156.57013   -3.089583   4.61       4.7018379
  44    -134.38454   -3.089583   4.61       4.6822723
  45    -112.534     -3.089583   4.61       4.7368687
  46    -91.39182    -3.089583   4.61       4.6743181
  47    -68.637731   -3.089583   4.61       4.7101696
  48    -46.676139   -3.089583   4.61       4.6119481
:::
:::

::: {#outline-container-org6a6e1d6 .outline-4}
#### Spat {#org6a6e1d6}

::: {#text-org6a6e1d6 .outline-text-4}
:::

-   []{#orge9b8f16}29 speakers\
    ::: {#text-orge9b8f16 .outline-text-5}
    Generate a file `spat_aed.txt` with the current speaker arrangments
    in Lilla Salen according to the table in for use with the Ircam spat
    package. The Scheme script below extracts the relevant data:

    ::: {.org-src-container}
    ``` {#org707ee92 .src .src-scheme}
    (define (spat_aed x y z result)
      (cond ((null? x) result)
            ((spat_aed (cdr x) (cdr y) (cdr z) (append result (list (car x) (car y) (car z)))))))
    (spat_aed aval eval dval '())
    ```
    :::

    The file generated by the script above to be used for a
    `spat.viewer @numspeakers 29 @showlistener 1 @viewpoint top @width 1200 @height 600`:

    ::: {.org-src-container}
    ``` {.src .src-shell}
    speakers aed
    -34.689614 12.910417 4.61 -13.383763 12.910417 4.61 10.440725 12.910417 4.61 32.117788 12.910417 4.61 55.741675 12.910417 4.61 78.207673 12.910417 4.61 101.49442 12.910417 4.61 124.85167 12.910417 4.61 147.91193 12.910417 4.61 169.17789 12.910417 4.61 -167.82013 12.910417 4.61 -145.63454 12.910417 4.61 -123.784 12.910417 4.61 -102.64182 12.910417 4.61 -79.887731 12.910417 4.61 -57.926139 12.910417 4.61 -22.349553 34.696822 4.882 22.843958 34.696822 4.882 69.013292 34.696822 4.882 115.56544 34.696822 4.882 158.89992 34.696822 4.882 -158.89763 34.696822 4.882 -114.65354 34.696822 4.882 -68.170128 34.696822 4.882 -45 69.185799 5.317 45 69.185799 5.317 135 69.185799 5.317 -135 69.185799 5.317 0 90 5.576
    ```
    :::
    :::

-   []{#org96152bb}45 speakers\
    ::: {#text-org96152bb .outline-text-5}
    Generate a file `spat_aed.txt` with the current speaker arrangments
    in Lilla Salen according to the table in for use with the Ircam spat
    package. The Scheme script extract the relevant data.

    ::: {.org-src-container}
    ``` {#org1a5c3ba .src .src-scheme}
    (define (spat_aed x y z result)
      (cond ((null? x) result)
            ((spat_aed (cdr x) (cdr y) (cdr z) (append result (list (car x) (car y) (car z)))))))
    (spat_aed aval eval dval '())
    ```
    :::

    The file generated by the script above to be used for a
    `spat.viewer @numspeakers 29 @showlistener 1 @viewpoint top @width 1200 @height 600`:

    ::: {.org-src-container}
    ``` {.src .src-shell}
    speakers aed
    -34.689614 12.910417 4.61 -13.383763 12.910417 4.61 10.440725 12.910417 4.61 32.117788 12.910417 4.61 55.741675 12.910417 4.61 78.207673 12.910417 4.61 101.49442 12.910417 4.61 124.85167 12.910417 4.61 147.91193 12.910417 4.61 169.17789 12.910417 4.61 -167.82013 12.910417 4.61 -145.63454 12.910417 4.61 -123.784 12.910417 4.61 -102.64182 12.910417 4.61 -79.887731 12.910417 4.61 -57.926139 12.910417 4.61 -22.349553 34.696822 4.882 22.843958 34.696822 4.882 69.013292 34.696822 4.882 115.56544 34.696822 4.882 158.89992 34.696822 4.882 -158.89763 34.696822 4.882 -114.65354 34.696822 4.882 -68.170128 34.696822 4.882 -45 69.185799 5.317 45 69.185799 5.317 135 69.185799 5.317 -135 69.185799 5.317 0 90 5.576
    ```
    :::
    :::
:::
:::
:::
:::

::: {#postamble .status}
Date: 2019-06-29 Lör 00:00

Author: Henrik Frisk

Created: 2019-07-02 Tis 12:50

[Validate](http://validator.w3.org/check?uri=referer)
:::
