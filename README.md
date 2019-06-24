

# Ambisonics in KMH studios and Lilla salen

## About the compiled decoders

All decoders use ACN channel order (see [Component order](#org73764d8)) and SN3D normalization (see [Normalisation](#orgcc22c51)) and are dual-band, max-rE/rV.


### A guide to the file names

For efficiency file names use the following format

1.  The space (KMHLS\_AE)
2.  Speaker configuration (FullSetup)
3.  Order (7H7P)
4.  Redundant speaker configuration (full)
5.  Type of decoder according to:

-   (1) AllRad mixed order (4/3)

    Mixed order ambisonics decoder.

-   (2) Decoding with the pseudoinverse

    Pinv decoders in 1st, 3rd order.

-   (4) Same as (2) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)

    1st and 3rd and 6th order.

-   (5) Spherical slepian decoders

    SSF decoders in 1st, 3rd and 6th order (6th order is here only as VST, but I can compile the other formats if needed.)

-   (6) All-round decoders

    AllRAD decoders in 1st, 3rd, 5th and 7th order.


### Formats

1.  VST
2.  Max/MSP (as package with help file to be put in ~/Documents/Max 7/Packages)
3.  Pd (bang left most input to get parameter names)
4.  SuperCollider (put all .sc and .scx in ~/Library/Application Support/SuperCollider/Extensions (supernova is of course optional)
5.  Ambix config file


### Speakers

In Klangkupolen the channel order from the mixer is channel 1-29 for the regular dome. The lower ring starts at channel 33-48 and the subs are at 49-52. This is the reason that in the decoder the names for the sixteen floor speakers start at 33.

### Speaker positions

Speaker index is counted linearly clockwise from FL. Subs are skipped.

<table id="orgb823ec3" border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-right">ndx</th>
<th scope="col" class="org-right">azimuth</th>
<th scope="col" class="org-right">elevation</th>
<th scope="col" class="org-right">distance</th>
</tr>


<tr>
<th scope="col" class="org-right">&#xa0;</th>
<th scope="col" class="org-right">&#xa0;</th>
<th scope="col" class="org-right">&#xa0;</th>
<th scope="col" class="org-right">&#xa0;</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-right">1</td>
<td class="org-right">24.6</td>
<td class="org-right">0</td>
<td class="org-right">3.26</td>
</tr>


<tr>
<td class="org-right">2</td>
<td class="org-right">0</td>
<td class="org-right">0</td>
<td class="org-right">3.27</td>
</tr>


<tr>
<td class="org-right">3</td>
<td class="org-right">-26.34</td>
<td class="org-right">0</td>
<td class="org-right">3.3</td>
</tr>


<tr>
<td class="org-right">4</td>
<td class="org-right">-58.7</td>
<td class="org-right">0</td>
<td class="org-right">3.35</td>
</tr>


<tr>
<td class="org-right">5</td>
<td class="org-right">-106</td>
<td class="org-right">0</td>
<td class="org-right">3.27</td>
</tr>


<tr>
<td class="org-right">6</td>
<td class="org-right">-129.35</td>
<td class="org-right">0</td>
<td class="org-right">3.364</td>
</tr>


<tr>
<td class="org-right">7</td>
<td class="org-right">129.35</td>
<td class="org-right">0</td>
<td class="org-right">3.376</td>
</tr>


<tr>
<td class="org-right">8</td>
<td class="org-right">106</td>
<td class="org-right">0</td>
<td class="org-right">3.262</td>
</tr>


<tr>
<td class="org-right">9</td>
<td class="org-right">58.7</td>
<td class="org-right">0</td>
<td class="org-right">3.296</td>
</tr>


<tr>
<td class="org-right">10</td>
<td class="org-right">45</td>
<td class="org-right">18</td>
<td class="org-right">3.02</td>
</tr>


<tr>
<td class="org-right">11</td>
<td class="org-right">-45</td>
<td class="org-right">18</td>
<td class="org-right">3.02</td>
</tr>


<tr>
<td class="org-right">12</td>
<td class="org-right">-135</td>
<td class="org-right">18</td>
<td class="org-right">3.05</td>
</tr>


<tr>
<td class="org-right">13</td>
<td class="org-right">135</td>
<td class="org-right">18</td>
<td class="org-right">3.02</td>
</tr>


<tr>
<td class="org-right">14</td>
<td class="org-right">0</td>
<td class="org-right">90</td>
<td class="org-right">1.60</td>
</tr>
</tbody>
</table>

### Comments

-   (1) AllRad mixed order (4/3)

    Mixed order ambisonics decoder

-   (2) Decoding with the pseudoinverse

    Pinv decoders in 1st and 3rd.

-   (4) Same as (2) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)

    Up to 3rd.

-   (5) Spherical slepian decoders

    SSF decoders in 1st, 3rd and 5th order (up to 6th).

-   (6) All-round decoders

    AllRAD decoders in 1st, 3rd, 5th and 7th order.

