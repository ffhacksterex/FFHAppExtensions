# ff1ext-golditems
#### esselle jaye

This sample project illlustrates an example of an ***experimental*** extension
support DLL. The project exports the functions expected by FFHacksterEx
and implements functionality for use with either a ROM or disassembly
that displays Gold using the price list values instead of the string table.

#### ff1ext-golditems.h/cpp
The header is defines import/export symbols.
The cpp file instantiates the CGoldItemsModule object that implements all functionality.

#### GoldItemsModule.h/cpp
Derived from CFFBaseApp, this class implements all functionality of the extension. \
It also furnishes to FFHacksterEx the details of what editors this extension
will add, override, or remove.

#### ff1ext-golditems.rc and Resource.h
This .rc is a listing of all of Windows resources that the program uses.  \
The header lists all IDs used to identity those resources.

#### res\ff1extgolditems.rc2
This file contains resources that are not edited by Microsoft
Visual C++.  You should place all resources not editable by
the resource editor in this file.

#### ff1ext-golditems.def
This file contains information about the DLL that must be
provided to run with Microsoft Windows.  It defines parameters
such as the name and description of the DLL.  It also exports
functions from the DLL.
