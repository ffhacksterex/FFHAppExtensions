# FFHExtensions
##### Esselle Jaye

This is a solution that shows one example of how
to develop extensions against FFHacksterEx.

In this case, the solution parent folder sites side-by-side with
the FFHEx solution parent folder and has a similar structure.

Startup Project: ff1ext-golditems (DLL)
\
&nbsp;
## WARNINGS

**WARNING:** \
  While Visual Studio verions later than 2015 can be used,
  be aware of their attempts to upgrade the projects to a compiler toolset
  later than 2015 140_xp.

  If you want to maintain support for XP, \
  DO ** **NOT** ** UPGRADE ANY PROJECT IN THE SOLUTION BEYOND THE 2015 140_xp TOOLSET!

  Since this release is a single codebase that targets both XP and later systems, 
  upgrading past 2015 140_xp introduces a large amount of breaking changes that also 
  make the project incompatible with XP. 
  The 2017 141_xp toolset doesn't work because parts of that toolset's standard library 
  (i.e. Microsoft's STL implementation) are implemented using functions that 
  were introduced in Vista and later, causing runtime errors when executed on XP.

  XP went out of support in 2014, but for the sake of those still using it for
  various reasons that support is retained for now.
  However, it will disappear at some point in 2022.
\
&nbsp;
## DIRECTORY STRUCTURE

The project directory structure is built in such a way that the code
itself is all in the src/ folder and artifacts built from it are placed
into siblings of that folder (dist/ and output/).

This mirrors the FFHEx project and relies on bnoth having
this structure. Note that becuase this solution includes the
FFHEx projects for ease of use, it also populates the
dist/ and output/ folders the same way FFHEx does.
See FFHEx for more details on that.

<pre>
FFHacksterEx/                                        The main folder containig everything else.
    dist/                                            Contains zip batch files that create deployable zips.
        ffhacksterex-win32-x86-v140_xp.zip
        ffhacksterex-win32-x86-v140_xp-debug.zip
        ffhacksterex-win64-x64-v140_xp.zip
        ffhacksterex-win64-x64-v140_xp-debug.zip
    output/                                          Contains build outputs.
        Debug/
            Win32/
            x64/
        Release/
            Win32/
            x64/
    src/                                             Contains all source code.
        .vs/
        apps/                                        Contains all projects producing EXEs.
            FFHacksterEx/
        dlls/                                        Contains all projects producing DLLs.
            ff1ext-golditems
        libs/                                        Contains all projects producing static LIBs.
            ff1-coredefs/
            ff1-editors/
            ff1-settings/
            ff1-subeditors/
            ff1-utils/
        txt/                                         Contains text and related informational files.
            readme.txt
        FFHExtensions.sln
</pre>
\
&nbsp;
## Golditems

The ff1ext-golditems project implements the extension.

It's also the startup project, so pressing F5 will launch
FFHex with ff1ext-golditems loaded into its address space.
This allow breakpoints in the DLL to work along with
breakpoints in the app and static libraries.
