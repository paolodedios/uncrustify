/**
 * @file change_int_types.cpp
 *
 * @author  Alex Henrie
 * @license GPL v2+
 */

#include "change_int_types.h"

#include "chunk.h"
#include "uncrustify.h"


using namespace uncrustify;


static void add_or_remove_int_keyword(Chunk *pc, iarf_e action)
{
   Chunk *next = pc->GetNextNcNnl();

   // Skip over all but the final type qualifier
   if (  strcmp(next->Text(), "const") == 0
      || strcmp(next->Text(), "long") == 0
      || strcmp(next->Text(), "short") == 0
      || strcmp(next->Text(), "signed") == 0
      || strcmp(next->Text(), "static") == 0
      || strcmp(next->Text(), "unsigned") == 0
      || strcmp(next->Text(), "volatile") == 0)
   {
      return;
   }

   if (strcmp(next->Text(), "int") == 0)
   {
      if (action == IARF_REMOVE)
      {
         Chunk::Delete(next);
      }
   }
   else if (  strcmp(next->Text(), "char") != 0
           && strcmp(next->Text(), "double") != 0)
   {
      if (  action == IARF_ADD
         || action == IARF_FORCE)
      {
         Chunk *int_keyword = pc->CopyAndAddAfter(pc);
         int_keyword->str = "int";
      }
   }
}


void change_int_types()
{
   LOG_FUNC_ENTRY();

   for (Chunk *pc = Chunk::GetHead(); pc->IsNotNullChunk(); pc = pc->GetNextNcNnl())
   {
      if (strcmp(pc->Text(), "short") == 0)
      {
         add_or_remove_int_keyword(pc, options::mod_short_int());
      }
      else if (strcmp(pc->Text(), "long") == 0)
      {
         add_or_remove_int_keyword(pc, options::mod_long_int());
      }
      else if (strcmp(pc->Text(), "signed") == 0)
      {
         add_or_remove_int_keyword(pc, options::mod_signed_int());
      }
      else if (strcmp(pc->Text(), "unsigned") == 0)
      {
         add_or_remove_int_keyword(pc, options::mod_unsigned_int());
      }
   }
}