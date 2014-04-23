
extern CHAR *GetNameChemDBConstants(ChemDBConstants *str)
{
     return(str->Name);
}

extern INT GetIDChemDBConstants(ChemDBConstants *str)
{
     return(str->ID);
}

extern ChemDBConstants *CreateChemDBConstants(ChemDBConstants *newstruct,
                                       INT id,
                                       CHAR *name,
                                       STRING *DBDirectory,
                                       STRING *DBMolRoot,
                                       STRING *DBSubstructureRoot,
                                       STRING *DBRxnRoot,
                                       STRING *DBDataDirectory,
                                       STRING *DBDataMolRoot,
                                       STRING *DBDataRxnRoot)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(DBDirectory != 0)
          {
          newstruct->DBDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDirectory, DBDirectory);
          }
     else
          newstruct->DBDirectory = 0;
     if(DBMolRoot != 0)
          {
          newstruct->DBMolRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBMolRoot, DBMolRoot);
          }
     else
          newstruct->DBMolRoot = 0;
     if(DBSubstructureRoot != 0)
          {
          newstruct->DBSubstructureRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBSubstructureRoot, DBSubstructureRoot);
          }
     else
          newstruct->DBSubstructureRoot = 0;
     if(DBRxnRoot != 0)
          {
          newstruct->DBRxnRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBRxnRoot, DBRxnRoot);
          }
     else
          newstruct->DBRxnRoot = 0;
     if(DBDataDirectory != 0)
          {
          newstruct->DBDataDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataDirectory, DBDataDirectory);
          }
     else
          newstruct->DBDataDirectory = 0;
     if(DBDataMolRoot != 0)
          {
          newstruct->DBDataMolRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataMolRoot, DBDataMolRoot);
          }
     else
          newstruct->DBDataMolRoot = 0;
     if(DBDataRxnRoot != 0)
          {
          newstruct->DBDataRxnRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataRxnRoot, DBDataRxnRoot);
          }
     else
          newstruct->DBDataRxnRoot = 0;



     return(newstruct);
}


extern void CopyFullChemDBConstants(ChemDBConstants *newstruct, ChemDBConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->DBDirectory != 0)
          {
          newstruct->DBDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDirectory, oldstruct->DBDirectory);
          }
     else
          newstruct->DBDirectory = 0;
     if(oldstruct->DBMolRoot != 0)
          {
          newstruct->DBMolRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBMolRoot, oldstruct->DBMolRoot);
          }
     else
          newstruct->DBMolRoot = 0;
     if(oldstruct->DBSubstructureRoot != 0)
          {
          newstruct->DBSubstructureRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBSubstructureRoot, oldstruct->DBSubstructureRoot);
          }
     else
          newstruct->DBSubstructureRoot = 0;
     if(oldstruct->DBRxnRoot != 0)
          {
          newstruct->DBRxnRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBRxnRoot, oldstruct->DBRxnRoot);
          }
     else
          newstruct->DBRxnRoot = 0;
     if(oldstruct->DBDataDirectory != 0)
          {
          newstruct->DBDataDirectory = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataDirectory, oldstruct->DBDataDirectory);
          }
     else
          newstruct->DBDataDirectory = 0;
     if(oldstruct->DBDataMolRoot != 0)
          {
          newstruct->DBDataMolRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataMolRoot, oldstruct->DBDataMolRoot);
          }
     else
          newstruct->DBDataMolRoot = 0;
     if(oldstruct->DBDataRxnRoot != 0)
          {
          newstruct->DBDataRxnRoot = AllocateSTRING;
          CopyFullSTRING(newstruct->DBDataRxnRoot, oldstruct->DBDataRxnRoot);
          }
     else
          newstruct->DBDataRxnRoot = 0;


}
extern void PrintChemDBConstants(ChemDBConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The database directory:\n");
     PrintSTRING(eleptr->DBDirectory);

     printf("The Molecule Database Root:\n");
     PrintSTRING(eleptr->DBMolRoot);

     printf("The Substructure Database Root:\n");
     PrintSTRING(eleptr->DBSubstructureRoot);

     printf("The Reaction Database Root:\n");
     PrintSTRING(eleptr->DBRxnRoot);

     printf("The data directory (ex. MolFiles):\n");
     PrintSTRING(eleptr->DBDataDirectory);

     printf("The Molecule Database Root:\n");
     PrintSTRING(eleptr->DBDataMolRoot);

     printf("The Reaction Database Root:\n");
     PrintSTRING(eleptr->DBDataRxnRoot);

}
extern void FreeChemDBConstants(ChemDBConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->DBDirectory);

     FreeSTRING(eleptr->DBMolRoot);

     FreeSTRING(eleptr->DBSubstructureRoot);

     FreeSTRING(eleptr->DBRxnRoot);

     FreeSTRING(eleptr->DBDataDirectory);

     FreeSTRING(eleptr->DBDataMolRoot);

     FreeSTRING(eleptr->DBDataRxnRoot);

}
extern void WriteBinChemDBConstants(ChemDBConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->DBDirectory,file);

     WriteBinSTRING(eleptr->DBMolRoot,file);

     WriteBinSTRING(eleptr->DBSubstructureRoot,file);

     WriteBinSTRING(eleptr->DBRxnRoot,file);

     WriteBinSTRING(eleptr->DBDataDirectory,file);

     WriteBinSTRING(eleptr->DBDataMolRoot,file);

     WriteBinSTRING(eleptr->DBDataRxnRoot,file);

}
extern INT ReadBinChemDBConstants(ChemDBConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->DBDirectory = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBDirectory,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBDirectory);
           eleptr->DBDirectory = 0;
           }

     eleptr->DBMolRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBMolRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBMolRoot);
           eleptr->DBMolRoot = 0;
           }

     eleptr->DBSubstructureRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBSubstructureRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBSubstructureRoot);
           eleptr->DBSubstructureRoot = 0;
           }

     eleptr->DBRxnRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBRxnRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBRxnRoot);
           eleptr->DBRxnRoot = 0;
           }

     eleptr->DBDataDirectory = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBDataDirectory,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBDataDirectory);
           eleptr->DBDataDirectory = 0;
           }

     eleptr->DBDataMolRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBDataMolRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBDataMolRoot);
           eleptr->DBDataMolRoot = 0;
           }

     eleptr->DBDataRxnRoot = AllocateSTRING;
     if(ReadBinSTRING(eleptr->DBDataRxnRoot,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DBDataRxnRoot);
           eleptr->DBDataRxnRoot = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ChemDBConstants(XDR *stream, char **eleptrp)
{
     ChemDBConstants *eleptr;
     eleptr = (ChemDBConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->DBDirectory),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBMolRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBSubstructureRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBRxnRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBDataDirectory),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBDataMolRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->DBDataRxnRoot),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocChemDBConstants()
{
     return((void *) AllocateChemDBConstants);
}

extern CHAR *GetNameChemDBMaster(ChemDBMaster *str)
{
     return(str->Name);
}

extern INT GetIDChemDBMaster(ChemDBMaster *str)
{
     return(str->ID);
}

extern ChemDBMaster *CreateChemDBMaster(ChemDBMaster *newstruct,
                                 INT id,
                                 CHAR *name,
                                 DbaseMaster *DatabaseInfo,
                                 ChemDBConstants *Constants)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(DatabaseInfo != 0)
          {
          newstruct->DatabaseInfo = AllocateDbaseMaster;
          CopyFullDbaseMaster(newstruct->DatabaseInfo, DatabaseInfo);
          }
     else
          newstruct->DatabaseInfo = 0;
     if(Constants != 0)
          {
          newstruct->Constants = AllocateChemDBConstants;
          CopyFullChemDBConstants(newstruct->Constants, Constants);
          }
     else
          newstruct->Constants = 0;



     return(newstruct);
}


extern void CopyFullChemDBMaster(ChemDBMaster *newstruct, ChemDBMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->DatabaseInfo != 0)
          {
          newstruct->DatabaseInfo = AllocateDbaseMaster;
          CopyFullDbaseMaster(newstruct->DatabaseInfo, oldstruct->DatabaseInfo);
          }
     else
          newstruct->DatabaseInfo = 0;
     if(oldstruct->Constants != 0)
          {
          newstruct->Constants = AllocateChemDBConstants;
          CopyFullChemDBConstants(newstruct->Constants, oldstruct->Constants);
          }
     else
          newstruct->Constants = 0;


}
extern void PrintChemDBMaster(ChemDBMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of databases:\n");
     PrintDbaseMaster(eleptr->DatabaseInfo);

     printf("  Database Constants:\n");
     PrintChemDBConstants(eleptr->Constants);

}
extern void FreeChemDBMaster(ChemDBMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeDbaseMaster(eleptr->DatabaseInfo);
     Free(eleptr->DatabaseInfo);

     FreeChemDBConstants(eleptr->Constants);
     Free(eleptr->Constants);

}
extern void WriteBinChemDBMaster(ChemDBMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinDbaseMaster(eleptr->DatabaseInfo,file);

     WriteBinChemDBConstants(eleptr->Constants,file);

}
extern INT ReadBinChemDBMaster(ChemDBMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->DatabaseInfo = AllocateDbaseMaster;
     if(ReadBinDbaseMaster(eleptr->DatabaseInfo,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DatabaseInfo);
           eleptr->DatabaseInfo = 0;
           }

     eleptr->Constants = AllocateChemDBConstants;
     if(ReadBinChemDBConstants(eleptr->Constants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Constants);
           eleptr->Constants = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ChemDBMaster(XDR *stream, char **eleptrp)
{
     ChemDBMaster *eleptr;
     eleptr = (ChemDBMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->DatabaseInfo),
          DbaseMasterSize,
                 (xdrproc_t) xdr_DbaseMaster);
     xdr_pointer(stream,
          (char **) &(eleptr->Constants),
          ChemDBConstantsSize,
                 (xdrproc_t) xdr_ChemDBConstants);
}

extern void *AllocChemDBMaster()
{
     return((void *) AllocateChemDBMaster);
}
