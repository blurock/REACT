
extern CHAR *GetNameDbaseKeyword(DbaseKeyword *str)
{
     return(str->Name);
}

extern INT GetIDDbaseKeyword(DbaseKeyword *str)
{
     return(str->ID);
}

extern DbaseKeyword *CreateDbaseKeyword(DbaseKeyword *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  Size,
                                 CHAR *KeyWord)
{
CHAR *oldKeyWord,*newKeyWord;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Size = Size;

     newstruct->KeyWord = AllocArrayCHAR(newstruct->Size);
     if(KeyWord != 0)
          {
          oldKeyWord = KeyWord;
          newKeyWord = newstruct->KeyWord;
          LOOPi(newstruct->Size)
               CopyFullCHAR(newKeyWord++, oldKeyWord++);
          }



     return(newstruct);
}


extern void CopyFullDbaseKeyword(DbaseKeyword *newstruct, DbaseKeyword *oldstruct)
{
CHAR *oldKeyWord,*newKeyWord;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Size = oldstruct->Size;


     newstruct->KeyWord = AllocArrayCHAR(newstruct->Size);
     if(oldstruct->KeyWord != 0)
          {
          oldKeyWord = oldstruct->KeyWord;
          newKeyWord = newstruct->KeyWord;
          LOOPi(newstruct->Size)
               CopyFullCHAR(newKeyWord++, oldKeyWord++);
          }


}
extern void PrintDbaseKeyword(DbaseKeyword *eleptr)
{
CHAR *ptrKeyWord;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The size of the Keyword:");
     printf("%d\n",eleptr->Size);

     printf("  The keyword itself:\n");
     if(eleptr->KeyWord != 0)
          {
          ptrKeyWord = eleptr->KeyWord;
          LOOPi(eleptr->Size)
               PrintCHAR(ptrKeyWord++);
          }


}
extern void FreeDbaseKeyword(DbaseKeyword *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->KeyWord);

}
extern void WriteBinDbaseKeyword(DbaseKeyword *eleptr, DbaseLinkedList *file)
{
CHAR *ptrKeyWord;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Size),file);

     if(eleptr->KeyWord != 0)
          {
          ptrKeyWord = eleptr->KeyWord;
          LOOPi(eleptr->Size)
               WriteBinCHAR(ptrKeyWord++,file);
          }

}
extern INT ReadBinDbaseKeyword(DbaseKeyword *eleptr,DbaseLinkedList *file)
     {
CHAR *ptrKeyWord;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Size),file);

          eleptr->KeyWord = AllocArrayCHAR(eleptr->Size);
          ptrKeyWord = eleptr->KeyWord;
          LOOPi(eleptr->Size)
               ReadBinCHAR(ptrKeyWord++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DbaseKeyword(XDR *stream, char **eleptrp)
{
     DbaseKeyword *eleptr;
     eleptr = (DbaseKeyword *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Size));

     xdr_array(stream,(char **) &(eleptr->KeyWord),
             (uint *) &(eleptr->Size),eleptr->Size,
               CHARSize,(xdrproc_t) xdr_CHAR);
}

extern void *AllocDbaseKeyword()
{
     return((void *) AllocateDbaseKeyword);
}

extern CHAR *GetNameSingleSearchKey(SingleSearchKey *str)
{
     return(str->Name);
}

extern INT GetIDSingleSearchKey(SingleSearchKey *str)
{
     return(str->ID);
}

extern SingleSearchKey *CreateSingleSearchKey(SingleSearchKey *newstruct,
                                       INT id,
                                       CHAR *name,
                                       DbaseKeyword *DBKey,
                                       DbaseKeyword *Search)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(DBKey != 0)
          {
          newstruct->DBKey = AllocateDbaseKeyword;
          CopyFullDbaseKeyword(newstruct->DBKey, DBKey);
          }
     else
          newstruct->DBKey = 0;
     if(Search != 0)
          {
          newstruct->Search = AllocateDbaseKeyword;
          CopyFullDbaseKeyword(newstruct->Search, Search);
          }
     else
          newstruct->Search = 0;



     return(newstruct);
}


extern void CopyFullSingleSearchKey(SingleSearchKey *newstruct, SingleSearchKey *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->DBKey != 0)
          {
          newstruct->DBKey = AllocateDbaseKeyword;
          CopyFullDbaseKeyword(newstruct->DBKey, oldstruct->DBKey);
          }
     else
          newstruct->DBKey = 0;
     if(oldstruct->Search != 0)
          {
          newstruct->Search = AllocateDbaseKeyword;
          CopyFullDbaseKeyword(newstruct->Search, oldstruct->Search);
          }
     else
          newstruct->Search = 0;


}
extern void PrintSingleSearchKey(SingleSearchKey *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("    The Database key:\n");
     PrintDbaseKeyword(eleptr->DBKey);

     printf("  The Search Keyword:\n");
     PrintDbaseKeyword(eleptr->Search);

}
extern void FreeSingleSearchKey(SingleSearchKey *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeDbaseKeyword(eleptr->DBKey);
     Free(eleptr->DBKey);

     FreeDbaseKeyword(eleptr->Search);
     Free(eleptr->Search);

}
extern void WriteBinSingleSearchKey(SingleSearchKey *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinDbaseKeyword(eleptr->DBKey,file);

     WriteBinDbaseKeyword(eleptr->Search,file);

}
extern INT ReadBinSingleSearchKey(SingleSearchKey *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->DBKey = AllocateDbaseKeyword;
     if(ReadBinDbaseKeyword(eleptr->DBKey,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBKey);
           eleptr->DBKey = 0;
           }

     eleptr->Search = AllocateDbaseKeyword;
     if(ReadBinDbaseKeyword(eleptr->Search,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Search);
           eleptr->Search = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SingleSearchKey(XDR *stream, char **eleptrp)
{
     SingleSearchKey *eleptr;
     eleptr = (SingleSearchKey *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->DBKey),
          DbaseKeywordSize,
                 (xdrproc_t) xdr_DbaseKeyword);
     xdr_pointer(stream,
          (char **) &(eleptr->Search),
          DbaseKeywordSize,
                 (xdrproc_t) xdr_DbaseKeyword);
}

extern void *AllocSingleSearchKey()
{
     return((void *) AllocateSingleSearchKey);
}

extern CHAR *GetNameSetOfSearchKeys(SetOfSearchKeys *str)
{
     return(str->Name);
}

extern INT GetIDSetOfSearchKeys(SetOfSearchKeys *str)
{
     return(str->ID);
}

extern SetOfSearchKeys *CreateSetOfSearchKeys(SetOfSearchKeys *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfAllocatedKeys,
                                       INT  NumberOfKeys,
                                       SingleSearchKey *Keys)
{
SingleSearchKey *oldKeys,*newKeys;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAllocatedKeys = NumberOfAllocatedKeys;
     newstruct->NumberOfKeys = NumberOfKeys;

     newstruct->Keys = AllocArraySingleSearchKey(newstruct->NumberOfKeys);
     if(Keys != 0)
          {
          oldKeys = Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullSingleSearchKey(newKeys++, oldKeys++);
          }



     return(newstruct);
}


extern void CopyFullSetOfSearchKeys(SetOfSearchKeys *newstruct, SetOfSearchKeys *oldstruct)
{
SingleSearchKey *oldKeys,*newKeys;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAllocatedKeys = oldstruct->NumberOfAllocatedKeys;
     newstruct->NumberOfKeys = oldstruct->NumberOfKeys;


     newstruct->Keys = AllocArraySingleSearchKey(newstruct->NumberOfKeys);
     if(oldstruct->Keys != 0)
          {
          oldKeys = oldstruct->Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullSingleSearchKey(newKeys++, oldKeys++);
          }


}
extern void PrintSetOfSearchKeys(SetOfSearchKeys *eleptr)
{
SingleSearchKey *ptrKeys;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The allocated number of search keys:");
     printf("%d\n",eleptr->NumberOfAllocatedKeys);
     printf("The number of filled in keys:");
     printf("%d\n",eleptr->NumberOfKeys);

     printf("           The keys :\n");
     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               PrintSingleSearchKey(ptrKeys++);
          }


}
extern void FreeSetOfSearchKeys(SetOfSearchKeys *eleptr)
{
SingleSearchKey *ptrKeys;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrKeys = eleptr->Keys;
     LOOPi(eleptr->NumberOfKeys)
          FreeSingleSearchKey(ptrKeys++);
     Free(eleptr->Keys);

}
extern void WriteBinSetOfSearchKeys(SetOfSearchKeys *eleptr, DbaseLinkedList *file)
{
SingleSearchKey *ptrKeys;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAllocatedKeys),file);
     WriteBinINT(&(eleptr->NumberOfKeys),file);

     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               WriteBinSingleSearchKey(ptrKeys++,file);
          }

}
extern INT ReadBinSetOfSearchKeys(SetOfSearchKeys *eleptr,DbaseLinkedList *file)
     {
SingleSearchKey *ptrKeys;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAllocatedKeys),file);
     ReadBinINT(&(eleptr->NumberOfKeys),file);

          eleptr->Keys = AllocArraySingleSearchKey(eleptr->NumberOfKeys);
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               ReadBinSingleSearchKey(ptrKeys++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfSearchKeys(XDR *stream, char **eleptrp)
{
     SetOfSearchKeys *eleptr;
     eleptr = (SetOfSearchKeys *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAllocatedKeys));
     xdr_INT(stream,(char **) &(eleptr->NumberOfKeys));

     xdr_array(stream,(char **) &(eleptr->Keys),
             (uint *) &(eleptr->NumberOfKeys),eleptr->NumberOfKeys,
               SingleSearchKeySize,(xdrproc_t) xdr_SingleSearchKey);
}

extern void *AllocSetOfSearchKeys()
{
     return((void *) AllocateSetOfSearchKeys);
}

extern CHAR *GetNameSearchKeyInfo(SearchKeyInfo *str)
{
     return(str->Name);
}

extern INT GetIDSearchKeyInfo(SearchKeyInfo *str)
{
     return(str->ID);
}

extern SearchKeyInfo *CreateSearchKeyInfo(SearchKeyInfo *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  InitialAllocation,
                                   INT  AllocationIncrement,
                                   SetOfSearchKeys *Keys,
                                   void  (*InsertKey)())
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->InitialAllocation = InitialAllocation;
     newstruct->AllocationIncrement = AllocationIncrement;
     newstruct->InsertKey = InsertKey;
     if(Keys != 0)
          {
          newstruct->Keys = AllocateSetOfSearchKeys;
          CopyFullSetOfSearchKeys(newstruct->Keys, Keys);
          }
     else
          newstruct->Keys = 0;



     return(newstruct);
}


extern void CopyFullSearchKeyInfo(SearchKeyInfo *newstruct, SearchKeyInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->InitialAllocation = oldstruct->InitialAllocation;
     newstruct->AllocationIncrement = oldstruct->AllocationIncrement;
     newstruct->InsertKey = oldstruct->InsertKey;

     if(oldstruct->Keys != 0)
          {
          newstruct->Keys = AllocateSetOfSearchKeys;
          CopyFullSetOfSearchKeys(newstruct->Keys, oldstruct->Keys);
          }
     else
          newstruct->Keys = 0;


}
extern void PrintSearchKeyInfo(SearchKeyInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The initial number of keys allocated:");
     printf("%d\n",eleptr->InitialAllocation);
     printf("The incremental allocation:");
     printf("%d\n",eleptr->AllocationIncrement);

     printf("     The set of keys:\n");
     PrintSetOfSearchKeys(eleptr->Keys);

}
extern void FreeSearchKeyInfo(SearchKeyInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfSearchKeys(eleptr->Keys);
     Free(eleptr->Keys);

}
extern void WriteBinSearchKeyInfo(SearchKeyInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->InitialAllocation),file);
     WriteBinINT(&(eleptr->AllocationIncrement),file);

     WriteBinSetOfSearchKeys(eleptr->Keys,file);

}
extern INT ReadBinSearchKeyInfo(SearchKeyInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->InitialAllocation),file);
     ReadBinINT(&(eleptr->AllocationIncrement),file);

     eleptr->Keys = AllocateSetOfSearchKeys;
     if(ReadBinSetOfSearchKeys(eleptr->Keys,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Keys);
           eleptr->Keys = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SearchKeyInfo(XDR *stream, char **eleptrp)
{
     SearchKeyInfo *eleptr;
     eleptr = (SearchKeyInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->InitialAllocation));
     xdr_INT(stream,(char **) &(eleptr->AllocationIncrement));

     xdr_pointer(stream,
          (char **) &(eleptr->Keys),
          SetOfSearchKeysSize,
                 (xdrproc_t) xdr_SetOfSearchKeys);
}

extern void *AllocSearchKeyInfo()
{
     return((void *) AllocateSearchKeyInfo);
}

extern CHAR *GetNameSetOfSearchKeyTypes(SetOfSearchKeyTypes *str)
{
     return(str->Name);
}

extern INT GetIDSetOfSearchKeyTypes(SetOfSearchKeyTypes *str)
{
     return(str->ID);
}

extern SetOfSearchKeyTypes *CreateSetOfSearchKeyTypes(SetOfSearchKeyTypes *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfAllocatedKeys,
                                               INT  NumberOfKeyTypes,
                                               SearchKeyInfo *KeyTypes)
{
SearchKeyInfo *oldKeyTypes,*newKeyTypes;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAllocatedKeys = NumberOfAllocatedKeys;
     newstruct->NumberOfKeyTypes = NumberOfKeyTypes;

     newstruct->KeyTypes = AllocArraySearchKeyInfo(newstruct->NumberOfKeyTypes);
     if(KeyTypes != 0)
          {
          oldKeyTypes = KeyTypes;
          newKeyTypes = newstruct->KeyTypes;
          LOOPi(newstruct->NumberOfKeyTypes)
               CopyFullSearchKeyInfo(newKeyTypes++, oldKeyTypes++);
          }



     return(newstruct);
}


extern void CopyFullSetOfSearchKeyTypes(SetOfSearchKeyTypes *newstruct, SetOfSearchKeyTypes *oldstruct)
{
SearchKeyInfo *oldKeyTypes,*newKeyTypes;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAllocatedKeys = oldstruct->NumberOfAllocatedKeys;
     newstruct->NumberOfKeyTypes = oldstruct->NumberOfKeyTypes;


     newstruct->KeyTypes = AllocArraySearchKeyInfo(newstruct->NumberOfKeyTypes);
     if(oldstruct->KeyTypes != 0)
          {
          oldKeyTypes = oldstruct->KeyTypes;
          newKeyTypes = newstruct->KeyTypes;
          LOOPi(newstruct->NumberOfKeyTypes)
               CopyFullSearchKeyInfo(newKeyTypes++, oldKeyTypes++);
          }


}
extern void PrintSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr)
{
SearchKeyInfo *ptrKeyTypes;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Allocated Keys:");
     printf("%d\n",eleptr->NumberOfAllocatedKeys);
     printf("The Number of Keys Types:");
     printf("%d\n",eleptr->NumberOfKeyTypes);

     printf("The set of key types:\n");
     if(eleptr->KeyTypes != 0)
          {
          ptrKeyTypes = eleptr->KeyTypes;
          LOOPi(eleptr->NumberOfKeyTypes)
               PrintSearchKeyInfo(ptrKeyTypes++);
          }


}
extern void FreeSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr)
{
SearchKeyInfo *ptrKeyTypes;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrKeyTypes = eleptr->KeyTypes;
     LOOPi(eleptr->NumberOfKeyTypes)
          FreeSearchKeyInfo(ptrKeyTypes++);
     Free(eleptr->KeyTypes);

}
extern void WriteBinSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr, DbaseLinkedList *file)
{
SearchKeyInfo *ptrKeyTypes;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAllocatedKeys),file);
     WriteBinINT(&(eleptr->NumberOfKeyTypes),file);

     if(eleptr->KeyTypes != 0)
          {
          ptrKeyTypes = eleptr->KeyTypes;
          LOOPi(eleptr->NumberOfKeyTypes)
               WriteBinSearchKeyInfo(ptrKeyTypes++,file);
          }

}
extern INT ReadBinSetOfSearchKeyTypes(SetOfSearchKeyTypes *eleptr,DbaseLinkedList *file)
     {
SearchKeyInfo *ptrKeyTypes;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAllocatedKeys),file);
     ReadBinINT(&(eleptr->NumberOfKeyTypes),file);

          eleptr->KeyTypes = AllocArraySearchKeyInfo(eleptr->NumberOfKeyTypes);
          ptrKeyTypes = eleptr->KeyTypes;
          LOOPi(eleptr->NumberOfKeyTypes)
               ReadBinSearchKeyInfo(ptrKeyTypes++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfSearchKeyTypes(XDR *stream, char **eleptrp)
{
     SetOfSearchKeyTypes *eleptr;
     eleptr = (SetOfSearchKeyTypes *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAllocatedKeys));
     xdr_INT(stream,(char **) &(eleptr->NumberOfKeyTypes));

     xdr_array(stream,(char **) &(eleptr->KeyTypes),
             (uint *) &(eleptr->NumberOfKeyTypes),eleptr->NumberOfKeyTypes,
               SearchKeyInfoSize,(xdrproc_t) xdr_SearchKeyInfo);
}

extern void *AllocSetOfSearchKeyTypes()
{
     return((void *) AllocateSetOfSearchKeyTypes);
}

extern CHAR *GetNameDataBaseInformation(DataBaseInformation *str)
{
     return(str->Name);
}

extern INT GetIDDataBaseInformation(DataBaseInformation *str)
{
     return(str->ID);
}

extern DataBaseInformation *CreateDataBaseInformation(DataBaseInformation *newstruct,
                                               INT id,
                                               CHAR *name,
                                               STRING *FilenameRoot,
                                               STRING *Directory,
                                               void  (*WriteConversion)(),
                                               INT  (*ReadConversion)(),
                                               VOID  File,
                                               SetOfSearchKeyTypes *Keys,
                                               VOID  (*AllocateElement)(),
                                               void  (*FreeElement)())
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->WriteConversion = WriteConversion;
     newstruct->ReadConversion = ReadConversion;
     newstruct->File = File;
     newstruct->AllocateElement = AllocateElement;
     newstruct->FreeElement = FreeElement;
     if(FilenameRoot != 0)
          {
          newstruct->FilenameRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->FilenameRoot, FilenameRoot);
          }
     else
          newstruct->FilenameRoot = 0;
     if(Directory != 0)
          {
          newstruct->Directory = AllocateSTRING;
          CopyFullSTRING(newstruct->Directory, Directory);
          }
     else
          newstruct->Directory = 0;
     if(Keys != 0)
          {
          newstruct->Keys = AllocateSetOfSearchKeyTypes;
          CopyFullSetOfSearchKeyTypes(newstruct->Keys, Keys);
          }
     else
          newstruct->Keys = 0;



     return(newstruct);
}


extern void CopyFullDataBaseInformation(DataBaseInformation *newstruct, DataBaseInformation *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->WriteConversion = oldstruct->WriteConversion;
     newstruct->ReadConversion = oldstruct->ReadConversion;
     newstruct->File = oldstruct->File;
     newstruct->AllocateElement = oldstruct->AllocateElement;
     newstruct->FreeElement = oldstruct->FreeElement;

     if(oldstruct->FilenameRoot != 0)
          {
          newstruct->FilenameRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->FilenameRoot, oldstruct->FilenameRoot);
          }
     else
          newstruct->FilenameRoot = 0;
     if(oldstruct->Directory != 0)
          {
          newstruct->Directory = AllocateSTRING;
          CopyFullSTRING(newstruct->Directory, oldstruct->Directory);
          }
     else
          newstruct->Directory = 0;
     if(oldstruct->Keys != 0)
          {
          newstruct->Keys = AllocateSetOfSearchKeyTypes;
          CopyFullSetOfSearchKeyTypes(newstruct->Keys, oldstruct->Keys);
          }
     else
          newstruct->Keys = 0;


}
extern void PrintDataBaseInformation(DataBaseInformation *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("   The filename root:\n");
     PrintSTRING(eleptr->FilenameRoot);

     printf("The Directory of the database:\n");
     PrintSTRING(eleptr->Directory);

     printf("Database Key Information:\n");
     PrintSetOfSearchKeyTypes(eleptr->Keys);

}
extern void FreeDataBaseInformation(DataBaseInformation *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->FilenameRoot);

     FreeSTRING(eleptr->Directory);

     FreeSetOfSearchKeyTypes(eleptr->Keys);
     Free(eleptr->Keys);

}
extern void WriteBinDataBaseInformation(DataBaseInformation *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->FilenameRoot,file);

     WriteBinSTRING(eleptr->Directory,file);

     WriteBinSetOfSearchKeyTypes(eleptr->Keys,file);

}
extern INT ReadBinDataBaseInformation(DataBaseInformation *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->FilenameRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->FilenameRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FilenameRoot);
           eleptr->FilenameRoot = 0;
           }

     eleptr->Directory = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Directory,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Directory);
           eleptr->Directory = 0;
           }

     eleptr->Keys = AllocateSetOfSearchKeyTypes;
     if(ReadBinSetOfSearchKeyTypes(eleptr->Keys,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Keys);
           eleptr->Keys = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DataBaseInformation(XDR *stream, char **eleptrp)
{
     DataBaseInformation *eleptr;
     eleptr = (DataBaseInformation *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->FilenameRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Directory),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Keys),
          SetOfSearchKeyTypesSize,
                 (xdrproc_t) xdr_SetOfSearchKeyTypes);
}

extern void *AllocDataBaseInformation()
{
     return((void *) AllocateDataBaseInformation);
}

extern CHAR *GetNameDbaseMaster(DbaseMaster *str)
{
     return(str->Name);
}

extern INT GetIDDbaseMaster(DbaseMaster *str)
{
     return(str->ID);
}

extern DbaseMaster *CreateDbaseMaster(DbaseMaster *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfDatabases,
                               DataBaseInformation *Databases)
{
DataBaseInformation *oldDatabases,*newDatabases;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfDatabases = NumberOfDatabases;

     newstruct->Databases = AllocArrayDataBaseInformation(newstruct->NumberOfDatabases);
     if(Databases != 0)
          {
          oldDatabases = Databases;
          newDatabases = newstruct->Databases;
          LOOPi(newstruct->NumberOfDatabases)
               CopyFullDataBaseInformation(newDatabases++, oldDatabases++);
          }



     return(newstruct);
}


extern void CopyFullDbaseMaster(DbaseMaster *newstruct, DbaseMaster *oldstruct)
{
DataBaseInformation *oldDatabases,*newDatabases;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfDatabases = oldstruct->NumberOfDatabases;


     newstruct->Databases = AllocArrayDataBaseInformation(newstruct->NumberOfDatabases);
     if(oldstruct->Databases != 0)
          {
          oldDatabases = oldstruct->Databases;
          newDatabases = newstruct->Databases;
          LOOPi(newstruct->NumberOfDatabases)
               CopyFullDataBaseInformation(newDatabases++, oldDatabases++);
          }


}
extern void PrintDbaseMaster(DbaseMaster *eleptr)
{
DataBaseInformation *ptrDatabases;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of databases:");
     printf("%d\n",eleptr->NumberOfDatabases);

     printf("The set of databases:\n");
     if(eleptr->Databases != 0)
          {
          ptrDatabases = eleptr->Databases;
          LOOPi(eleptr->NumberOfDatabases)
               PrintDataBaseInformation(ptrDatabases++);
          }


}
extern void FreeDbaseMaster(DbaseMaster *eleptr)
{
DataBaseInformation *ptrDatabases;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrDatabases = eleptr->Databases;
     LOOPi(eleptr->NumberOfDatabases)
          FreeDataBaseInformation(ptrDatabases++);
     Free(eleptr->Databases);

}
extern void WriteBinDbaseMaster(DbaseMaster *eleptr, DbaseLinkedList *file)
{
DataBaseInformation *ptrDatabases;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfDatabases),file);

     if(eleptr->Databases != 0)
          {
          ptrDatabases = eleptr->Databases;
          LOOPi(eleptr->NumberOfDatabases)
               WriteBinDataBaseInformation(ptrDatabases++,file);
          }

}
extern INT ReadBinDbaseMaster(DbaseMaster *eleptr,DbaseLinkedList *file)
     {
DataBaseInformation *ptrDatabases;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfDatabases),file);

          eleptr->Databases = AllocArrayDataBaseInformation(eleptr->NumberOfDatabases);
          ptrDatabases = eleptr->Databases;
          LOOPi(eleptr->NumberOfDatabases)
               ReadBinDataBaseInformation(ptrDatabases++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DbaseMaster(XDR *stream, char **eleptrp)
{
     DbaseMaster *eleptr;
     eleptr = (DbaseMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfDatabases));

     xdr_array(stream,(char **) &(eleptr->Databases),
             (uint *) &(eleptr->NumberOfDatabases),eleptr->NumberOfDatabases,
               DataBaseInformationSize,(xdrproc_t) xdr_DataBaseInformation);
}

extern void *AllocDbaseMaster()
{
     return((void *) AllocateDbaseMaster);
}
