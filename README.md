# FDF
## Codam Coding College project FDF

![Demo of 42.fdf](https://github.com/jdsmith022/fdf_/blob/master/pictures/fdf.gif)

### Description
Fdf is a program written in C that displays a 3D representation of a relief landscape given as parameter passed to the program. The coordinates of the landscape are stored in the 'map' given as paramater and are used to create a simplified graphic wireframe.

The objectives of this project are to discover the basics of graphic programming and, in particular, how to place points in space, join them with segments, and how to observe the scene from a particular viewpoint. This project introduced me to "events" programming and is the first project in which I used the graphic library miniLibX.

For full pdf of project requirements click [here](https://github.com/jdsmith022/fdf/blob/master/fdf.en.pdf).

### Prerequities
XQuartz
To download click [here](https://www.xquartz.org/).

### Installation

From terminal, the program can be install with git clone with the project repository, followed by the name of the directory you wish to download the repository to.

#### Example 
```
$ git clone git@github.com:jdsmith022/fdf.git [directory-name]
```

### Usage
In terminal, go into the project directory. This program uses a makefile to compile. To compile, run:
```
$ make
```
The executable name is fdf. A directory in the repository named maps has a list of landscape maps that can be used. To see names of maps available for use is maps directory of repository, from terminal and in git repository:
```
$ ls -la maps/
```
![ls-la display](https://github.com/jdsmith022/fdf_/blob/master/pictures/ls-la.png)

However, a relief map from the local computer can be used as long as the path to the file is given as parameter.
```
$ ./fdf [path-to-map]
```

#### Example:
```
$ ./fdf maps/42.fdf
```

As a bonus feature, the program can take color as parameter from the map file. The largest maps, julia.fdf and fractol.fdf, have this feature and, as a result, takes longer to process. If color is given with map, colors cannot be changed via the user interface.

If incorrect parameters are given or the map is invalid, a usage error will be given. The user interface provides information for the use and exit of the program. 

fractol.fdf:
![fractol.fdf](https://github.com/jdsmith022/fdf_/blob/master/pictures/fractal.png)

42.fdf:
![42.fdf](https://github.com/jdsmith022/fdf_/blob/master/pictures/42.png)

To delete all object files from directory, run:
```
$ make clean
```
To delete executable from directory, run:
```
$ make fclean
```


### Collaborator
This project was a group effort with:
[Malou](https://github.com/mminkjan)
