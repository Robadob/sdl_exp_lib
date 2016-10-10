Development tends to follow our requirements and interests, so there will be lacking functioanlity. If you have good ideas or reuqirements make an issue, if you'd liked to include your own code make a pull request. Try and follow the below style guidelines.

# Style Guidelines
*I(Rob) started off programming with VB.net and then Java so, the style is somewhat influenced by those roots.*

## Identifiers
* Classes/Filenames: UpperCamelCase
* Methods/Variables/Parameters: lowerCamelCase
* Constants: SNAKE_CASE *(This does not include const parameters)*
* Device Pointers (if using CUDA): d_lowerCamelCase *the d_ is simply prepended to the front of the normal naming scheme*

## Object Orientation
This lib is largely a low-level OOP C++ wrapper to OpenGL, providing more friendly and automated handling of things such as shaders and textures. It has also grown to incorporate slightly more functional items such as the skybox class to save reimplementation. The library itself as a whole uses SDL to provide a window. However it's preferable where possible that classes can be used away from the library with minimal additional code or changes. Therefore where a member function takes a parameter of (a pointer to) a different class, where feasible the specified class should be a minimal interface/base-class which can be reimplemented by a user if desired. Sub-classes of `Viewport` are an exception to this rule, due to them providing the highest level interface to the library. Similarly any manager (UI, Particle) classes, are likely to rely on the relevant classes they manage.

## Smart Pointers
* Use them please.

## Defensive Programming
* If a function/parameter can be marked as `const`, it should be. *(Some suggest starting with everything `const`, and removing as necessary)*
* All OpenGL methods are to wrapped with `GL_CALL()` or followed by `GL_CHECK()` as defined in `GLcheck.h`
* Do the same as above for any CUDA calls.

## Tabs
* 4-spaces are to be used. *(This isn't the visual studio default, and can easily be find-replaced from tab chars so don't worry too much.)*
* If a particular method contains alot of nesting, consider switching to 2-spaces to improve visibility.
* If all else fails, just be consistent with tab depth.

## Testing
* None to speak of, feel free to introduce some, most testing occurs in the form of "Does OpenGL report any errors? Y/N"

## Comments
* All methods and classes should have a documenting comment.
* Documentation comments should follow the Javadoc style as specified at [doxygen](https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html).
* If a method is becoming long and unweildy introducing descriptive comments within the method will improve maintainability.
