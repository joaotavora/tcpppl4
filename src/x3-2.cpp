/**
   Q: What does a compiler do?  What does a linker do?

   A: A compiler takes a piece of code written in a high-level
   programming language and produces machine-level code for it.  The
   machine code is stored in a file called a translation unit.  Some
   operations in that code are the invocation of named routines whose
   machine code is not immediately available at the site of the
   invocation.  They may or may not be available within the
   translation unit.  Either way, this doesn't prevent the creation of
   the translation unit.

   A linker takes a set of translation units and makes sure that the
   machine code for all invocation routines is found and suitalbly
   linked together from the site of all the invocations.  When
   producing an application meant to be invoked by directly by the
   user, it also ensures there is a special entry-point routine,
   usually called main().
*/

#ifdef EXERCISE_MAIN
int main() {
  return 0;
}
#endif
