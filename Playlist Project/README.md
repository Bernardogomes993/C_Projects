# Dynamic Playlist Manager in C
This project is a system to manage playlists in C. This project has **Nested Linked Lists** using
RAM and the data persistence using **binary serialization**.

## Functionalities
**Creation of multiple playlists**: The user can create an unlimited number of playlists as long as
the RAM allows.
**Managing Songs**: This program allows the user to insert or remove songs in the desired playlist.
**Validation of duplicates**: The program does not allow repeated names for playlists or songs or artists.
**Binary Persistence (`playlist.bin`)**: The program writes and reads each byte from the hard disk. The file
contains structural metadata (sizes) in order to restore the pointers and the structs.
**Remove of a song**: The algorithm manipulates the pointers in a way that any song can be removed without
breaking the list.(`free()`).

## Memory Architecture
This project uses the `malloc()` function to allocate memory dynamically, the struct is divided by:
**Playlist Node**: This `struct` has the playlist name, a pointer for the next playlist and other pointer
to the music `struct`.
**Music Node**: This `struct` has the name of the song , name of the artist and a pointer to the next song.

### Binary File Hierarchy
* `[INT]` -> Total Number of Playlists
  * `[CHAR[50]]` -> Name of the first playlist
  * `[INT]` -> Number of songs of the first playlist
    * `[CHAR[50]]` -> Name of the first music
    * `[CHAR[50]]` -> Name of the first artist
  * *...Repeats for the remainder songs and playlists...*
Maybe later adding a new functionalitie to remove a playlist entirely.
