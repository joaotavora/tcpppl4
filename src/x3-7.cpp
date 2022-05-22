/**
   Q: What is an invariant and what good might it do?

   A: In computing, an invariant is a set of assumptions that a given
   operation always expects of its operands before it is able to
   perform any meaningful computation.  If those assumptions don't
   hold (if the invariant has "varied"), then said computation is
   meaningless.  Either the invariant was erroneously identified or it
   its protection wasn't enforced."

   Let's think of the operands of those operations as entities that
   are alive during a (brief) period of time.  Then, the invariant are
   each entities' fundamental characteristics.  If those fundaments
   varied during its lifetime, the entity would cease to exist
   validly, or would magically transmute into another type of entity.
   Either way all operations on it would cease to have useful meaning.

   In the specific context of Object Oriented programming, we call
   those entities "object".  It's very useful to identify/recognize a
   given object's invariants or -- better yet -- doing that for a
   given family of objects -- a type.  Then we can view the family as
   a provider of operations whose operands are objects of said family
   type.  Those operations collectively make sure never to destroy or
   invalidate the object's invariants.

   If we operate on the object exclusively through those operations,
   we will always have meaningful results.  In other words, an object
   such a type is guaranteed to exist validly during its lifetime.

   That, in turn, is a property of great value when using that type to
   express (or to "model") the invariants of other types.
*/

#ifdef EXERCISE_MAIN
int main() {
  return 0;
}
#endif
