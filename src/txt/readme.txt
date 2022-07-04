
FFHExtensions
Esselle Jaye
===========================

This solution hosts extensions used wih FFHacksterEx.
The solution is designed to reside in th esame directory as the
FFHacksterEx folder (which contains /src, /output/, and /dist subfolders.)

Startup Project: ff1ext-golditems
  or any other ff1ext-* project added to th esolution.

Versioning:
  See below.


===========================

/// WARNINGS ///

WARNING:
  While Visual Studio verions later than 2015 van be used,
  beware of their attempts to upgrade the projects to a compiler toolset
  later than 2015 140_xp.

  DO **NOT** UPGRADE ANY PROJECT IN THE SOLUTION BEYOND THE 2015 140_xp TOOLSET!

  Since this release is a single codebase that targets both XP and 
  later systems, upgrading past 2015 140_xp introduces a large amount 
  of breaking changes that also make the project incompatible with XP. 
  The 2017 141_xp toolset doesn't work because some of that toolset's 
  standard library (i.e. STL) components are implemented using functions that 
  were introduced in Vista and later, causing runtime errors when executed on XP.

  XP went out of support in 2014, but for the sake of those still using it for
  various reasons that support is retained for now.
  However, it will disappear at some point in 2022.


WARNING:
  Opening the solution sometimes loses track of the active start up project.
  This tends to happen when the .suo file is corrupted.
  To address it:
  - close the solution
  - go to the solution folder (which contains the .sln file).
  - navigate to the .vs/FFHExtensions subfolder
  - delete the .suo file, then reopen the solution
  - set the ff1ext-*. project of your choice as the startup project
  - it should remain set once you close and reopen the solution henceforth.



C:\CODE\essellejaye\FFHExtensionsC:\CODE\essellejaye\FFHExtensions
===========================

/// ff1ext-golditems ///

This sample extension reimplements the game's gold handling such that it
displays gold values by dynamically generating the strings instead
of storing them in the string table.
This frees those strings for use by other features.
It also adds a gold editor to maniuplate the gold values and updates
editors to load the values from the gold price list instead of
the gold strings.
This isn't meant to be a standalone hack so much as to
a) provide an example of how to build an extension DLL, and
b) provide a base for other extensions that can reuse the freed strings.

- ff1ext-golditems.h/cpp
  Implements the Invoke exported method used by FFHEx to invoke the
  editors defined within this extension module. It instantiates and
  calls the module that handles the editors.

- GoldItemsModule.h/cpp
  Implements the CFFBaseAPp-derived class that manages the state
   of the module an dactually invokes the editors.

- GoldEntriesLoader.h/cpp
  Extends EntriesLoader to relabel the Gold strings heading as Unused
  and to load the gold values fro the price list instead of the strings.

- TextSansGold.h/cpp
  Text editor with the Gold category renamed to Unused.


/// Versioning ///

Various executable projects contain version-number.h files.
The version-number.h file contains macros defining the version
as both tokens and a string.
If you want to implement auto-incrementing, then you can target
this header file to accomplish that.
