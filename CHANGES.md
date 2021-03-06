
# Version History {#CHANGES}

# Version 0.6.4
*Date: 2021-02-02*

- Fixed missing `#pragma once` in ImageRenderer.h

# Version 0.6.3
*Date: 2021-01-20*

- Changed Matrix3 class to be a template and moved it to public include folder.
- Improved `Palette` class.
- Extended and improved `ImageRenderer` class.
- The documentation of the Full API has been updated and slightly extended.

# Version 0.6.1
*Date: 2021-01-14*

- Added option to specify the maximum recursion depth the the scene quadtree in `ImageRenderer` class.

# Version 0.6.0
*Date: 2021-01-13*

- Removed some warnings emitted by MS compilers.
- Fixed missing `#pragma once` in AstUtils0.h
- Added `RotateDeg` method to `Vector2` class.
- Added class ' `ColorHsv` to cover HSV color space as well.
- Better encapsulation of internal functions for SDL applications (API-Level 0).
- Added `RenderRegularPolygon` function for SDL application (API-Level 0).

# Version 0.5.3
*Date: 2020-12-16*
- Extended `Color` class.

# Version 0.5.2
*Date: 2020-12-10*

- Extended `Vector2` template with multiplication operator between two vectors.
- Fixed issue regarding outdated version information.

# Version 0.5.1
*Date: 2020-12-09*

- Added convenient function `SayError()` for easy error output.
- Refactored `Vector2` class to be a template class.
- Added `Vector2d` alias for `astu::Vector2<double>`.
- Improved support for SDL-based applications using API-level 0.

# Version 0.4.0
*Date: 2020-11-25*

- Added service facility for simulations and games.
- Added Entity Component System (ECS) to be used for simulations and games.
- Added template for mathematical vectors in three dimensional space.
- Started to add basic support for SDL-based application for API-level 0.

# Version 0.3.0
*Date: 2020-10-21*

- Initial public release.
- Fixed bug in ask functions causing `AskString` not to work after calling `AskInt` etc.
- Improved error module.
- Added additional math functions.
- Fixed some issues, e.g, compiler warnings and errors on macOS and Windows. 
- Started to work on full access level functions and classes.
- Improved Image class.

# Version 0.2.0
*Date: 2020-08-19*

- Output methods can optionally omit end-of-line from output.
- Added module for error handling.
- Added module for audio processing (API-Level 0).

# Version 0.1.0
*Date: 2020-08-14*

- Initial version.