
extern CHAR *GetNameAliasString(AliasString *str)
{
     return(str->Name);
}

extern INT GetIDAliasString(AliasString *str)
{
     return(str->ID);
}

extern AliasString *CreateAliasString(AliasString *newstruct,
                               INT id,
                               CHAR *name,
                               STRING *KeyWord,
                               STRING *Alias)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(KeyWord != 0)
          {
          newstruct->KeyWord = AllocateSTRING;
          CopyFullSTRING(newstruct->KeyWord, KeyWord);
          }
     else
          newstruct->KeyWord = 0;
     if(Alias != 0)
          {
          newstruct->Alias = AllocateSTRING;
          CopyFullSTRING(newstruct->Alias, Alias);
          }
     else
          newstruct->Alias = 0;



     return(newstruct);
}


extern void CopyFullAliasString(AliasString *newstruct, AliasString *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->KeyWord != 0)
          {
          newstruct->KeyWord = AllocateSTRING;
          CopyFullSTRING(newstruct->KeyWord, oldstruct->KeyWord);
          }
     else
          newstruct->KeyWord = 0;
     if(oldstruct->Alias != 0)
          {
          newstruct->Alias = AllocateSTRING;
          CopyFullSTRING(newstruct->Alias, oldstruct->Alias);
          }
     else
          newstruct->Alias = 0;


}
extern void PrintAliasString(AliasString *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The string to be substituted:\n");
     PrintSTRING(eleptr->KeyWord);

     printf("The value to be inserted for keyword:\n");
     PrintSTRING(eleptr->Alias);

}
extern void FreeAliasString(AliasString *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->KeyWord);

     FreeSTRING(eleptr->Alias);

}
extern void WriteBinAliasString(AliasString *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->KeyWord,file);

     WriteBinSTRING(eleptr->Alias,file);

}
extern INT ReadBinAliasString(AliasString *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->KeyWord = AllocateSTRING;
     if(ReadBinSTRING(eleptr->KeyWord,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->KeyWord);
           eleptr->KeyWord = 0;
           }

     eleptr->Alias = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Alias,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Alias);
           eleptr->Alias = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_AliasString(XDR *stream, char **eleptrp)
{
     AliasString *eleptr;
     eleptr = (AliasString *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->KeyWord),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Alias),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocAliasString()
{
     return((void *) AllocateAliasString);
}

extern CHAR *GetNameAliasArray(AliasArray *str)
{
     return(str->Name);
}

extern INT GetIDAliasArray(AliasArray *str)
{
     return(str->ID);
}

extern AliasArray *CreateAliasArray(AliasArray *newstruct,
                             INT id,
                             CHAR *name,
                             INT  MaxNumber,
                             INT  NumberOfAliases,
                             AliasString *Set)
{
AliasString *oldSet,*newSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MaxNumber = MaxNumber;
     newstruct->NumberOfAliases = NumberOfAliases;

     newstruct->Set = AllocArrayAliasString(newstruct->NumberOfAliases);
     if(Set != 0)
          {
          oldSet = Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfAliases)
               CopyFullAliasString(newSet++, oldSet++);
          }



     return(newstruct);
}


extern void CopyFullAliasArray(AliasArray *newstruct, AliasArray *oldstruct)
{
AliasString *oldSet,*newSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MaxNumber = oldstruct->MaxNumber;
     newstruct->NumberOfAliases = oldstruct->NumberOfAliases;


     newstruct->Set = AllocArrayAliasString(newstruct->NumberOfAliases);
     if(oldstruct->Set != 0)
          {
          oldSet = oldstruct->Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfAliases)
               CopyFullAliasString(newSet++, oldSet++);
          }


}
extern void PrintAliasArray(AliasArray *eleptr)
{
AliasString *ptrSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The maximum (for add alias routine):");
     printf("%d\n",eleptr->MaxNumber);
     printf("The number of aliases:");
     printf("%d\n",eleptr->NumberOfAliases);

     printf("  The Set of Aliases:\n");
     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfAliases)
               PrintAliasString(ptrSet++);
          }


}
extern void FreeAliasArray(AliasArray *eleptr)
{
AliasString *ptrSet;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSet = eleptr->Set;
     LOOPi(eleptr->NumberOfAliases)
          FreeAliasString(ptrSet++);
     Free(eleptr->Set);

}
extern void WriteBinAliasArray(AliasArray *eleptr, DbaseLinkedList *file)
{
AliasString *ptrSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MaxNumber),file);
     WriteBinINT(&(eleptr->NumberOfAliases),file);

     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfAliases)
               WriteBinAliasString(ptrSet++,file);
          }

}
extern INT ReadBinAliasArray(AliasArray *eleptr,DbaseLinkedList *file)
     {
AliasString *ptrSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MaxNumber),file);
     ReadBinINT(&(eleptr->NumberOfAliases),file);

          eleptr->Set = AllocArrayAliasString(eleptr->NumberOfAliases);
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfAliases)
               ReadBinAliasString(ptrSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_AliasArray(XDR *stream, char **eleptrp)
{
     AliasArray *eleptr;
     eleptr = (AliasArray *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MaxNumber));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAliases));

     xdr_array(stream,(char **) &(eleptr->Set),
             (uint *) &(eleptr->NumberOfAliases),eleptr->NumberOfAliases,
               AliasStringSize,(xdrproc_t) xdr_AliasString);
}

extern void *AllocAliasArray()
{
     return((void *) AllocateAliasArray);
}

extern CHAR *GetNameCommandLevel(CommandLevel *str)
{
     return(str->Name);
}

extern INT GetIDCommandLevel(CommandLevel *str)
{
     return(str->ID);
}

extern CommandLevel *CreateCommandLevel(CommandLevel *newstruct,
                                 INT id,
                                 CHAR *name,
                                 CommandLevel *Next)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Next != 0)
          {
          newstruct->Next = AllocateCommandLevel;
          CopyFullCommandLevel(newstruct->Next, Next);
          }
     else
          newstruct->Next = 0;



     return(newstruct);
}


extern void CopyFullCommandLevel(CommandLevel *newstruct, CommandLevel *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Next != 0)
          {
          newstruct->Next = AllocateCommandLevel;
          CopyFullCommandLevel(newstruct->Next, oldstruct->Next);
          }
     else
          newstruct->Next = 0;


}
extern void PrintCommandLevel(CommandLevel *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The next Deeper Level:\n");
     PrintCommandLevel(eleptr->Next);

}
extern void FreeCommandLevel(CommandLevel *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeCommandLevel(eleptr->Next);
     Free(eleptr->Next);

}
extern void WriteBinCommandLevel(CommandLevel *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinCommandLevel(eleptr->Next,file);

}
extern INT ReadBinCommandLevel(CommandLevel *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Next = AllocateCommandLevel;
     if(ReadBinCommandLevel(eleptr->Next,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Next);
           eleptr->Next = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_CommandLevel(XDR *stream, char **eleptrp)
{
     CommandLevel *eleptr;
     eleptr = (CommandLevel *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Next),
          CommandLevelSize,
                 (xdrproc_t) xdr_CommandLevel);
}

extern void *AllocCommandLevel()
{
     return((void *) AllocateCommandLevel);
}

extern CHAR *GetNameStringBuffer(StringBuffer *str)
{
     return(str->Name);
}

extern INT GetIDStringBuffer(StringBuffer *str)
{
     return(str->ID);
}

extern StringBuffer *CreateStringBuffer(StringBuffer *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  BufferLeft,
                                 STRING *OutputBuffer,
                                 FILE *OutputFile)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->BufferLeft = BufferLeft;
     if(OutputBuffer != 0)
          {
          newstruct->OutputBuffer = AllocateSTRING;
          CopyFullSTRING(newstruct->OutputBuffer, OutputBuffer);
          }
     else
          newstruct->OutputBuffer = 0;
     if(OutputFile != 0)
          {
          newstruct->OutputFile = AllocateFILE;
          CopyFullFILE(newstruct->OutputFile, OutputFile);
          }
     else
          newstruct->OutputFile = 0;



     return(newstruct);
}


extern void CopyFullStringBuffer(StringBuffer *newstruct, StringBuffer *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->BufferLeft = oldstruct->BufferLeft;

     if(oldstruct->OutputBuffer != 0)
          {
          newstruct->OutputBuffer = AllocateSTRING;
          CopyFullSTRING(newstruct->OutputBuffer, oldstruct->OutputBuffer);
          }
     else
          newstruct->OutputBuffer = 0;
     if(oldstruct->OutputFile != 0)
          {
          newstruct->OutputFile = AllocateFILE;
          CopyFullFILE(newstruct->OutputFile, oldstruct->OutputFile);
          }
     else
          newstruct->OutputFile = 0;


}
extern void PrintStringBuffer(StringBuffer *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of bytes left in the buffer:");
     printf("%d\n",eleptr->BufferLeft);

     printf("   The output buffer:\n");
     PrintSTRING(eleptr->OutputBuffer);

     printf("The associated file to print to:\n");
     PrintFILE(eleptr->OutputFile);

}
extern void FreeStringBuffer(StringBuffer *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->OutputBuffer);

     Free(eleptr->OutputFile);

}
extern void WriteBinStringBuffer(StringBuffer *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->BufferLeft),file);

     WriteBinSTRING(eleptr->OutputBuffer,file);

     WriteBinFILE(eleptr->OutputFile,file);

}
extern INT ReadBinStringBuffer(StringBuffer *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->BufferLeft),file);

     eleptr->OutputBuffer = AllocateSTRING;
     if(ReadBinSTRING(eleptr->OutputBuffer,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->OutputBuffer);
           eleptr->OutputBuffer = 0;
           }

     eleptr->OutputFile = AllocateFILE;
     if(ReadBinFILE(eleptr->OutputFile,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->OutputFile);
           eleptr->OutputFile = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_StringBuffer(XDR *stream, char **eleptrp)
{
     StringBuffer *eleptr;
     eleptr = (StringBuffer *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->BufferLeft));

     xdr_pointer(stream,
          (char **) &(eleptr->OutputBuffer),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->OutputFile),
          FILESize,
                 (xdrproc_t) xdr_FILE);
}

extern void *AllocStringBuffer()
{
     return((void *) AllocateStringBuffer);
}

extern CHAR *GetNameErrorStatus(ErrorStatus *str)
{
     return(str->Name);
}

extern INT GetIDErrorStatus(ErrorStatus *str)
{
     return(str->ID);
}

extern ErrorStatus *CreateErrorStatus(ErrorStatus *newstruct,
                               INT id,
                               CHAR *name,
                               INT  EStatus,
                               INT  ErrorRecovery)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->EStatus = EStatus;
     newstruct->ErrorRecovery = ErrorRecovery;



     return(newstruct);
}


extern void CopyFullErrorStatus(ErrorStatus *newstruct, ErrorStatus *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->EStatus = oldstruct->EStatus;
     newstruct->ErrorRecovery = oldstruct->ErrorRecovery;



}
extern void PrintErrorStatus(ErrorStatus *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Error Status Flag:");
     printf("%d\n",eleptr->EStatus);
     printf("What to do to recover from an error:");
     printf("%d\n",eleptr->ErrorRecovery);

}
extern void FreeErrorStatus(ErrorStatus *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinErrorStatus(ErrorStatus *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->EStatus),file);
     WriteBinINT(&(eleptr->ErrorRecovery),file);

}
extern INT ReadBinErrorStatus(ErrorStatus *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->EStatus),file);
     ReadBinINT(&(eleptr->ErrorRecovery),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ErrorStatus(XDR *stream, char **eleptrp)
{
     ErrorStatus *eleptr;
     eleptr = (ErrorStatus *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->EStatus));
     xdr_INT(stream,(char **) &(eleptr->ErrorRecovery));

}

extern void *AllocErrorStatus()
{
     return((void *) AllocateErrorStatus);
}

extern CHAR *GetNameCommandSource(CommandSource *str)
{
     return(str->Name);
}

extern INT GetIDCommandSource(CommandSource *str)
{
     return(str->ID);
}

extern CommandSource *CreateCommandSource(CommandSource *newstruct,
                                   INT id,
                                   CHAR *name,
                                   FILE *File,
                                   CommandReturn *Command,
                                   ErrorStatus *ErrorStat,
                                   INT  Verbose,
                                   StringBuffer *StandardOut,
                                   StringBuffer *ProtocolOut,
                                   StringBuffer *ErrorOut)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Verbose = Verbose;
     if(File != 0)
          {
          newstruct->File = AllocateFILE;
          CopyFullFILE(newstruct->File, File);
          }
     else
          newstruct->File = 0;
     if(Command != 0)
          {
          newstruct->Command = AllocateCommandReturn;
          CopyFullCommandReturn(newstruct->Command, Command);
          }
     else
          newstruct->Command = 0;
     if(ErrorStat != 0)
          {
          newstruct->ErrorStat = AllocateErrorStatus;
          CopyFullErrorStatus(newstruct->ErrorStat, ErrorStat);
          }
     else
          newstruct->ErrorStat = 0;
     if(StandardOut != 0)
          {
          newstruct->StandardOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->StandardOut, StandardOut);
          }
     else
          newstruct->StandardOut = 0;
     if(ProtocolOut != 0)
          {
          newstruct->ProtocolOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->ProtocolOut, ProtocolOut);
          }
     else
          newstruct->ProtocolOut = 0;
     if(ErrorOut != 0)
          {
          newstruct->ErrorOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->ErrorOut, ErrorOut);
          }
     else
          newstruct->ErrorOut = 0;



     return(newstruct);
}


extern void CopyFullCommandSource(CommandSource *newstruct, CommandSource *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Verbose = oldstruct->Verbose;

     if(oldstruct->File != 0)
          {
          newstruct->File = AllocateFILE;
          CopyFullFILE(newstruct->File, oldstruct->File);
          }
     else
          newstruct->File = 0;
     if(oldstruct->Command != 0)
          {
          newstruct->Command = AllocateCommandReturn;
          CopyFullCommandReturn(newstruct->Command, oldstruct->Command);
          }
     else
          newstruct->Command = 0;
     if(oldstruct->ErrorStat != 0)
          {
          newstruct->ErrorStat = AllocateErrorStatus;
          CopyFullErrorStatus(newstruct->ErrorStat, oldstruct->ErrorStat);
          }
     else
          newstruct->ErrorStat = 0;
     if(oldstruct->StandardOut != 0)
          {
          newstruct->StandardOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->StandardOut, oldstruct->StandardOut);
          }
     else
          newstruct->StandardOut = 0;
     if(oldstruct->ProtocolOut != 0)
          {
          newstruct->ProtocolOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->ProtocolOut, oldstruct->ProtocolOut);
          }
     else
          newstruct->ProtocolOut = 0;
     if(oldstruct->ErrorOut != 0)
          {
          newstruct->ErrorOut = AllocateStringBuffer;
          CopyFullStringBuffer(newstruct->ErrorOut, oldstruct->ErrorOut);
          }
     else
          newstruct->ErrorOut = 0;


}
extern void PrintCommandSource(CommandSource *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("This is the level of Verbose printout:");
     printf("%d\n",eleptr->Verbose);

     printf("This is the source ASCII file under Batch Mode:\n");
     PrintFILE(eleptr->File);

     printf("This is the Current Command Line in Batch Mode:\n");
     PrintCommandReturn(eleptr->Command);

     printf("This is what to do in case of an error:\n");
     PrintErrorStatus(eleptr->ErrorStat);

     printf("This is the standard ASCII out:\n");
     PrintStringBuffer(eleptr->StandardOut);

     printf("This is the standard ASCII protocol:\n");
     PrintStringBuffer(eleptr->ProtocolOut);

     printf(" This is the standard error:\n");
     PrintStringBuffer(eleptr->ErrorOut);

}
extern void FreeCommandSource(CommandSource *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->File);

     FreeCommandReturn(eleptr->Command);
     Free(eleptr->Command);

     FreeErrorStatus(eleptr->ErrorStat);
     Free(eleptr->ErrorStat);

     FreeStringBuffer(eleptr->StandardOut);
     Free(eleptr->StandardOut);

     FreeStringBuffer(eleptr->ProtocolOut);
     Free(eleptr->ProtocolOut);

     FreeStringBuffer(eleptr->ErrorOut);
     Free(eleptr->ErrorOut);

}
extern void WriteBinCommandSource(CommandSource *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Verbose),file);

     WriteBinFILE(eleptr->File,file);

     WriteBinCommandReturn(eleptr->Command,file);

     WriteBinErrorStatus(eleptr->ErrorStat,file);

     WriteBinStringBuffer(eleptr->StandardOut,file);

     WriteBinStringBuffer(eleptr->ProtocolOut,file);

     WriteBinStringBuffer(eleptr->ErrorOut,file);

}
extern INT ReadBinCommandSource(CommandSource *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Verbose),file);

     eleptr->File = AllocateFILE;
     if(ReadBinFILE(eleptr->File,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->File);
           eleptr->File = 0;
           }

     eleptr->Command = AllocateCommandReturn;
     if(ReadBinCommandReturn(eleptr->Command,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Command);
           eleptr->Command = 0;
           }

     eleptr->ErrorStat = AllocateErrorStatus;
     if(ReadBinErrorStatus(eleptr->ErrorStat,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ErrorStat);
           eleptr->ErrorStat = 0;
           }

     eleptr->StandardOut = AllocateStringBuffer;
     if(ReadBinStringBuffer(eleptr->StandardOut,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->StandardOut);
           eleptr->StandardOut = 0;
           }

     eleptr->ProtocolOut = AllocateStringBuffer;
     if(ReadBinStringBuffer(eleptr->ProtocolOut,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ProtocolOut);
           eleptr->ProtocolOut = 0;
           }

     eleptr->ErrorOut = AllocateStringBuffer;
     if(ReadBinStringBuffer(eleptr->ErrorOut,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ErrorOut);
           eleptr->ErrorOut = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_CommandSource(XDR *stream, char **eleptrp)
{
     CommandSource *eleptr;
     eleptr = (CommandSource *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Verbose));

     xdr_pointer(stream,
          (char **) &(eleptr->File),
          FILESize,
                 (xdrproc_t) xdr_FILE);
     xdr_pointer(stream,
          (char **) &(eleptr->Command),
          CommandReturnSize,
                 (xdrproc_t) xdr_CommandReturn);
     xdr_pointer(stream,
          (char **) &(eleptr->ErrorStat),
          ErrorStatusSize,
                 (xdrproc_t) xdr_ErrorStatus);
     xdr_pointer(stream,
          (char **) &(eleptr->StandardOut),
          StringBufferSize,
                 (xdrproc_t) xdr_StringBuffer);
     xdr_pointer(stream,
          (char **) &(eleptr->ProtocolOut),
          StringBufferSize,
                 (xdrproc_t) xdr_StringBuffer);
     xdr_pointer(stream,
          (char **) &(eleptr->ErrorOut),
          StringBufferSize,
                 (xdrproc_t) xdr_StringBuffer);
}

extern void *AllocCommandSource()
{
     return((void *) AllocateCommandSource);
}

extern CHAR *GetNameFunctionList(FunctionList *str)
{
     return(str->Name);
}

extern INT GetIDFunctionList(FunctionList *str)
{
     return(str->ID);
}

extern FunctionList *CreateFunctionList(FunctionList *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfFunctions,
                                 FunctionInfo *Function)
{
FunctionInfo *oldFunction,*newFunction;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfFunctions = NumberOfFunctions;

     newstruct->Function = AllocArrayFunctionInfo(newstruct->NumberOfFunctions);
     if(Function != 0)
          {
          oldFunction = Function;
          newFunction = newstruct->Function;
          LOOPi(newstruct->NumberOfFunctions)
               CopyFullFunctionInfo(newFunction++, oldFunction++);
          }



     return(newstruct);
}


extern void CopyFullFunctionList(FunctionList *newstruct, FunctionList *oldstruct)
{
FunctionInfo *oldFunction,*newFunction;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfFunctions = oldstruct->NumberOfFunctions;


     newstruct->Function = AllocArrayFunctionInfo(newstruct->NumberOfFunctions);
     if(oldstruct->Function != 0)
          {
          oldFunction = oldstruct->Function;
          newFunction = newstruct->Function;
          LOOPi(newstruct->NumberOfFunctions)
               CopyFullFunctionInfo(newFunction++, oldFunction++);
          }


}
extern void PrintFunctionList(FunctionList *eleptr)
{
FunctionInfo *ptrFunction;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of functions in the list:");
     printf("%d\n",eleptr->NumberOfFunctions);

     printf("The List of Functions:\n");
     if(eleptr->Function != 0)
          {
          ptrFunction = eleptr->Function;
          LOOPi(eleptr->NumberOfFunctions)
               PrintFunctionInfo(ptrFunction++);
          }


}
extern void FreeFunctionList(FunctionList *eleptr)
{
FunctionInfo *ptrFunction;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrFunction = eleptr->Function;
     LOOPi(eleptr->NumberOfFunctions)
          FreeFunctionInfo(ptrFunction++);
     Free(eleptr->Function);

}
extern void WriteBinFunctionList(FunctionList *eleptr, DbaseLinkedList *file)
{
FunctionInfo *ptrFunction;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfFunctions),file);

     if(eleptr->Function != 0)
          {
          ptrFunction = eleptr->Function;
          LOOPi(eleptr->NumberOfFunctions)
               WriteBinFunctionInfo(ptrFunction++,file);
          }

}
extern INT ReadBinFunctionList(FunctionList *eleptr,DbaseLinkedList *file)
     {
FunctionInfo *ptrFunction;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfFunctions),file);

          eleptr->Function = AllocArrayFunctionInfo(eleptr->NumberOfFunctions);
          ptrFunction = eleptr->Function;
          LOOPi(eleptr->NumberOfFunctions)
               ReadBinFunctionInfo(ptrFunction++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_FunctionList(XDR *stream, char **eleptrp)
{
     FunctionList *eleptr;
     eleptr = (FunctionList *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfFunctions));

     xdr_array(stream,(char **) &(eleptr->Function),
             (uint *) &(eleptr->NumberOfFunctions),eleptr->NumberOfFunctions,
               FunctionInfoSize,(xdrproc_t) xdr_FunctionInfo);
}

extern void *AllocFunctionList()
{
     return((void *) AllocateFunctionList);
}

extern CHAR *GetNameCommandMaster(CommandMaster *str)
{
     return(str->Name);
}

extern INT GetIDCommandMaster(CommandMaster *str)
{
     return(str->ID);
}

extern CommandMaster *CreateCommandMaster(CommandMaster *newstruct,
                                   INT id,
                                   CHAR *name,
                                   CommandSource *Source,
                                   CommandInfo *Commands,
                                   FunctionList *Functions,
                                   CommandLevel *Levels,
                                   VOID  MasterProgInfo,
                                   CommandInfo *Utilities,
                                   AliasArray *AliasSet)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MasterProgInfo = MasterProgInfo;
     if(Source != 0)
          {
          newstruct->Source = AllocateCommandSource;
          CopyFullCommandSource(newstruct->Source, Source);
          }
     else
          newstruct->Source = 0;
     if(Commands != 0)
          {
          newstruct->Commands = AllocateCommandInfo;
          CopyFullCommandInfo(newstruct->Commands, Commands);
          }
     else
          newstruct->Commands = 0;
     if(Functions != 0)
          {
          newstruct->Functions = AllocateFunctionList;
          CopyFullFunctionList(newstruct->Functions, Functions);
          }
     else
          newstruct->Functions = 0;
     if(Levels != 0)
          {
          newstruct->Levels = AllocateCommandLevel;
          CopyFullCommandLevel(newstruct->Levels, Levels);
          }
     else
          newstruct->Levels = 0;
     if(Utilities != 0)
          {
          newstruct->Utilities = AllocateCommandInfo;
          CopyFullCommandInfo(newstruct->Utilities, Utilities);
          }
     else
          newstruct->Utilities = 0;
     if(AliasSet != 0)
          {
          newstruct->AliasSet = AllocateAliasArray;
          CopyFullAliasArray(newstruct->AliasSet, AliasSet);
          }
     else
          newstruct->AliasSet = 0;



     return(newstruct);
}


extern void CopyFullCommandMaster(CommandMaster *newstruct, CommandMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MasterProgInfo = oldstruct->MasterProgInfo;

     if(oldstruct->Source != 0)
          {
          newstruct->Source = AllocateCommandSource;
          CopyFullCommandSource(newstruct->Source, oldstruct->Source);
          }
     else
          newstruct->Source = 0;
     if(oldstruct->Commands != 0)
          {
          newstruct->Commands = AllocateCommandInfo;
          CopyFullCommandInfo(newstruct->Commands, oldstruct->Commands);
          }
     else
          newstruct->Commands = 0;
     if(oldstruct->Functions != 0)
          {
          newstruct->Functions = AllocateFunctionList;
          CopyFullFunctionList(newstruct->Functions, oldstruct->Functions);
          }
     else
          newstruct->Functions = 0;
     if(oldstruct->Levels != 0)
          {
          newstruct->Levels = AllocateCommandLevel;
          CopyFullCommandLevel(newstruct->Levels, oldstruct->Levels);
          }
     else
          newstruct->Levels = 0;
     if(oldstruct->Utilities != 0)
          {
          newstruct->Utilities = AllocateCommandInfo;
          CopyFullCommandInfo(newstruct->Utilities, oldstruct->Utilities);
          }
     else
          newstruct->Utilities = 0;
     if(oldstruct->AliasSet != 0)
          {
          newstruct->AliasSet = AllocateAliasArray;
          CopyFullAliasArray(newstruct->AliasSet, oldstruct->AliasSet);
          }
     else
          newstruct->AliasSet = 0;


}
extern void PrintCommandMaster(CommandMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("This is Input Source Information:\n");
     PrintCommandSource(eleptr->Source);

     printf("This is the main command tree:\n");
     PrintCommandInfo(eleptr->Commands);

     printf("This are the list of available functions:\n");
     PrintFunctionList(eleptr->Functions);

     printf("These are the levels of Command:\n");
     PrintCommandLevel(eleptr->Levels);

     printf("These are the Utility (fixed) Commands:\n");
     PrintCommandInfo(eleptr->Utilities);

     printf("  The set of aliases:\n");
     PrintAliasArray(eleptr->AliasSet);

}
extern void FreeCommandMaster(CommandMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeCommandSource(eleptr->Source);
     Free(eleptr->Source);

     FreeCommandInfo(eleptr->Commands);
     Free(eleptr->Commands);

     FreeFunctionList(eleptr->Functions);
     Free(eleptr->Functions);

     FreeCommandLevel(eleptr->Levels);
     Free(eleptr->Levels);

     FreeCommandInfo(eleptr->Utilities);
     Free(eleptr->Utilities);

     FreeAliasArray(eleptr->AliasSet);
     Free(eleptr->AliasSet);

}
extern void WriteBinCommandMaster(CommandMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinCommandSource(eleptr->Source,file);

     WriteBinCommandInfo(eleptr->Commands,file);

     WriteBinFunctionList(eleptr->Functions,file);

     WriteBinCommandLevel(eleptr->Levels,file);

     WriteBinCommandInfo(eleptr->Utilities,file);

     WriteBinAliasArray(eleptr->AliasSet,file);

}
extern INT ReadBinCommandMaster(CommandMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Source = AllocateCommandSource;
     if(ReadBinCommandSource(eleptr->Source,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Source);
           eleptr->Source = 0;
           }

     eleptr->Commands = AllocateCommandInfo;
     if(ReadBinCommandInfo(eleptr->Commands,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Commands);
           eleptr->Commands = 0;
           }

     eleptr->Functions = AllocateFunctionList;
     if(ReadBinFunctionList(eleptr->Functions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Functions);
           eleptr->Functions = 0;
           }

     eleptr->Levels = AllocateCommandLevel;
     if(ReadBinCommandLevel(eleptr->Levels,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Levels);
           eleptr->Levels = 0;
           }

     eleptr->Utilities = AllocateCommandInfo;
     if(ReadBinCommandInfo(eleptr->Utilities,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Utilities);
           eleptr->Utilities = 0;
           }

     eleptr->AliasSet = AllocateAliasArray;
     if(ReadBinAliasArray(eleptr->AliasSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AliasSet);
           eleptr->AliasSet = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_CommandMaster(XDR *stream, char **eleptrp)
{
     CommandMaster *eleptr;
     eleptr = (CommandMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Source),
          CommandSourceSize,
                 (xdrproc_t) xdr_CommandSource);
     xdr_pointer(stream,
          (char **) &(eleptr->Commands),
          CommandInfoSize,
                 (xdrproc_t) xdr_CommandInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->Functions),
          FunctionListSize,
                 (xdrproc_t) xdr_FunctionList);
     xdr_pointer(stream,
          (char **) &(eleptr->Levels),
          CommandLevelSize,
                 (xdrproc_t) xdr_CommandLevel);
     xdr_pointer(stream,
          (char **) &(eleptr->Utilities),
          CommandInfoSize,
                 (xdrproc_t) xdr_CommandInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->AliasSet),
          AliasArraySize,
                 (xdrproc_t) xdr_AliasArray);
}

extern void *AllocCommandMaster()
{
     return((void *) AllocateCommandMaster);
}
