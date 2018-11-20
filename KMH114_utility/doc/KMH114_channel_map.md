
### `Channel mapping plugin` 
//
Channel mapping plugin that takes 15 channels of input (center speaker included)
and maps it to the channel/speaker configuration of the studio 114 according to:

* 1 -> 1 
* 2 -> 2 
* 3 -> 14 
* 4 -> 15 
* 5 -> 7 
* 6 -> 4 
* 7 -> 8 
* 8 -> 3 
* 9 -> 6 
* 10 -> 5 
* 11 -> 9
* 12 -> 10
* 13 -> 12
* 14 -> 11
* 15 -> 13
* 16 -> 16

Method: traverse the channel order of the ambisonics output and define the speaker
number in the studio configuration

---

