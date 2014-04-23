
extern CHAR *GetNameBensonAtomConnections(BensonAtomConnections *str)
{
     return(str->Name);
}

extern INT GetIDBensonAtomConnections(BensonAtomConnections *str)
{
     return(str->ID);
}

extern BensonAtomConnections *CreateBensonAtomConnections(BensonAtomConnections *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Valence,
                                                   INT  Multiplicity)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Valence = Valence;
     newstruct->Multiplicity = Multiplicity;



     return(newstruct);
}


extern void CopyFullBensonAtomConnections(BensonAtomConnections *newstruct, BensonAtomConnections *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Valence = oldstruct->Valence;
     newstruct->Multiplicity = oldstruct->Multiplicity;



}
extern void PrintBensonAtomConnections(BensonAtomConnections *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Atom Valence Value:");
     printf("%d\n",eleptr->Valence);
     printf("    The Multiplicity:");
     printf("%d\n",eleptr->Multiplicity);

}
extern void FreeBensonAtomConnections(BensonAtomConnections *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinBensonAtomConnections(BensonAtomConnections *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Valence),file);
     WriteBinINT(&(eleptr->Multiplicity),file);

}
extern INT ReadBinBensonAtomConnections(BensonAtomConnections *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Valence),file);
     ReadBinINT(&(eleptr->Multiplicity),file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonAtomConnections(XDR *stream, char **eleptrp)
{
     BensonAtomConnections *eleptr;
     eleptr = (BensonAtomConnections *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Valence));
     xdr_INT(stream,(char **) &(eleptr->Multiplicity));

}

extern void *AllocBensonAtomConnections()
{
     return((void *) AllocateBensonAtomConnections);
}

extern CHAR *GetNameBensonSecondThermoTable(BensonSecondThermoTable *str)
{
     return(str->Name);
}

extern INT GetIDBensonSecondThermoTable(BensonSecondThermoTable *str)
{
     return(str->ID);
}

extern BensonSecondThermoTable *CreateBensonSecondThermoTable(BensonSecondThermoTable *newstruct,
INT id,
CHAR *name,
FLOAT  HeatOfFormation,
FLOAT  Entropy,
INT  NumberOfHeatCapacityValues,
FLOAT *HeatCapacityValues)
{
FLOAT *oldHeatCapacityValues,*newHeatCapacityValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->HeatOfFormation = HeatOfFormation;
     newstruct->Entropy = Entropy;
     newstruct->NumberOfHeatCapacityValues = NumberOfHeatCapacityValues;

     newstruct->HeatCapacityValues = AllocArrayFLOAT(newstruct->NumberOfHeatCapacityValues);
     if(HeatCapacityValues != 0)
          {
          oldHeatCapacityValues = HeatCapacityValues;
          newHeatCapacityValues = newstruct->HeatCapacityValues;
          LOOPi(newstruct->NumberOfHeatCapacityValues)
               CopyFullFLOAT(newHeatCapacityValues++, oldHeatCapacityValues++);
          }



     return(newstruct);
}


extern void CopyFullBensonSecondThermoTable(BensonSecondThermoTable *newstruct, BensonSecondThermoTable *oldstruct)
{
FLOAT *oldHeatCapacityValues,*newHeatCapacityValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->HeatOfFormation = oldstruct->HeatOfFormation;
     newstruct->Entropy = oldstruct->Entropy;
     newstruct->NumberOfHeatCapacityValues = oldstruct->NumberOfHeatCapacityValues;


     newstruct->HeatCapacityValues = AllocArrayFLOAT(newstruct->NumberOfHeatCapacityValues);
     if(oldstruct->HeatCapacityValues != 0)
          {
          oldHeatCapacityValues = oldstruct->HeatCapacityValues;
          newHeatCapacityValues = newstruct->HeatCapacityValues;
          LOOPi(newstruct->NumberOfHeatCapacityValues)
               CopyFullFLOAT(newHeatCapacityValues++, oldHeatCapacityValues++);
          }


}
extern void PrintBensonSecondThermoTable(BensonSecondThermoTable *eleptr)
{
FLOAT *ptrHeatCapacityValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("   Heat Of Formation:");
     printf("%f\n",eleptr->HeatOfFormation);
     printf("             Entropy:");
     printf("%f\n",eleptr->Entropy);
     printf("The number of heat capacity values:");
     printf("%d\n",eleptr->NumberOfHeatCapacityValues);

     printf("   The set of Values:\n");
     if(eleptr->HeatCapacityValues != 0)
          {
          ptrHeatCapacityValues = eleptr->HeatCapacityValues;
          LOOPi(eleptr->NumberOfHeatCapacityValues)
               PrintFLOAT(ptrHeatCapacityValues++);
          }


}
extern void FreeBensonSecondThermoTable(BensonSecondThermoTable *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->HeatCapacityValues);

}
extern void WriteBinBensonSecondThermoTable(BensonSecondThermoTable *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrHeatCapacityValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->HeatOfFormation),file);
     WriteBinFLOAT(&(eleptr->Entropy),file);
     WriteBinINT(&(eleptr->NumberOfHeatCapacityValues),file);

     if(eleptr->HeatCapacityValues != 0)
          {
          ptrHeatCapacityValues = eleptr->HeatCapacityValues;
          LOOPi(eleptr->NumberOfHeatCapacityValues)
               WriteBinFLOAT(ptrHeatCapacityValues++,file);
          }

}
extern INT ReadBinBensonSecondThermoTable(BensonSecondThermoTable *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrHeatCapacityValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->HeatOfFormation),file);
     ReadBinFLOAT(&(eleptr->Entropy),file);
     ReadBinINT(&(eleptr->NumberOfHeatCapacityValues),file);

          eleptr->HeatCapacityValues = AllocArrayFLOAT(eleptr->NumberOfHeatCapacityValues);
          ptrHeatCapacityValues = eleptr->HeatCapacityValues;
          LOOPi(eleptr->NumberOfHeatCapacityValues)
               ReadBinFLOAT(ptrHeatCapacityValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonSecondThermoTable(XDR *stream, char **eleptrp)
{
     BensonSecondThermoTable *eleptr;
     eleptr = (BensonSecondThermoTable *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->HeatOfFormation));
     xdr_FLOAT(stream,(char **) &(eleptr->Entropy));
     xdr_INT(stream,(char **) &(eleptr->NumberOfHeatCapacityValues));

     xdr_array(stream,(char **) &(eleptr->HeatCapacityValues),
             (uint *) &(eleptr->NumberOfHeatCapacityValues),eleptr->NumberOfHeatCapacityValues,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocBensonSecondThermoTable()
{
     return((void *) AllocateBensonSecondThermoTable);
}

extern CHAR *GetNameBensonSecondOrder(BensonSecondOrder *str)
{
     return(str->Name);
}

extern INT GetIDBensonSecondOrder(BensonSecondOrder *str)
{
     return(str->ID);
}

extern BensonSecondOrder *CreateBensonSecondOrder(BensonSecondOrder *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  CenterAtom,
                                           INT  NumberOfConnections,
                                           BensonAtomConnections *Connections,
                                           BensonSecondThermoTable *TableValues)
{
BensonAtomConnections *oldConnections,*newConnections;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->CenterAtom = CenterAtom;
     newstruct->NumberOfConnections = NumberOfConnections;
     if(TableValues != 0)
          {
          newstruct->TableValues = AllocateBensonSecondThermoTable;
          CopyFullBensonSecondThermoTable(newstruct->TableValues, TableValues);
          }
     else
          newstruct->TableValues = 0;

     newstruct->Connections = AllocArrayBensonAtomConnections(newstruct->NumberOfConnections);
     if(Connections != 0)
          {
          oldConnections = Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfConnections)
               CopyFullBensonAtomConnections(newConnections++, oldConnections++);
          }



     return(newstruct);
}


extern void CopyFullBensonSecondOrder(BensonSecondOrder *newstruct, BensonSecondOrder *oldstruct)
{
BensonAtomConnections *oldConnections,*newConnections;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->CenterAtom = oldstruct->CenterAtom;
     newstruct->NumberOfConnections = oldstruct->NumberOfConnections;

     if(oldstruct->TableValues != 0)
          {
          newstruct->TableValues = AllocateBensonSecondThermoTable;
          CopyFullBensonSecondThermoTable(newstruct->TableValues, oldstruct->TableValues);
          }
     else
          newstruct->TableValues = 0;

     newstruct->Connections = AllocArrayBensonAtomConnections(newstruct->NumberOfConnections);
     if(oldstruct->Connections != 0)
          {
          oldConnections = oldstruct->Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfConnections)
               CopyFullBensonAtomConnections(newConnections++, oldConnections++);
          }


}
extern void PrintBensonSecondOrder(BensonSecondOrder *eleptr)
{
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Center Atom Valence:");
     printf("%d\n",eleptr->CenterAtom);
     printf("The number of Types Connected:");
     printf("%d\n",eleptr->NumberOfConnections);

     printf("The thermodynamic information:\n");
     PrintBensonSecondThermoTable(eleptr->TableValues);

     printf("The set of Connection Types:\n");
     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfConnections)
               PrintBensonAtomConnections(ptrConnections++);
          }


}
extern void FreeBensonSecondOrder(BensonSecondOrder *eleptr)
{
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrConnections = eleptr->Connections;
     LOOPi(eleptr->NumberOfConnections)
          FreeBensonAtomConnections(ptrConnections++);
     Free(eleptr->Connections);

     FreeBensonSecondThermoTable(eleptr->TableValues);
     Free(eleptr->TableValues);

}
extern void WriteBinBensonSecondOrder(BensonSecondOrder *eleptr, DbaseLinkedList *file)
{
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->CenterAtom),file);
     WriteBinINT(&(eleptr->NumberOfConnections),file);

     WriteBinBensonSecondThermoTable(eleptr->TableValues,file);

     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfConnections)
               WriteBinBensonAtomConnections(ptrConnections++,file);
          }

}
extern INT ReadBinBensonSecondOrder(BensonSecondOrder *eleptr,DbaseLinkedList *file)
     {
BensonAtomConnections *ptrConnections;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->CenterAtom),file);
     ReadBinINT(&(eleptr->NumberOfConnections),file);

     eleptr->TableValues = AllocateBensonSecondThermoTable;
     if(ReadBinBensonSecondThermoTable(eleptr->TableValues,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->TableValues);
           eleptr->TableValues = 0;
           }

          eleptr->Connections = AllocArrayBensonAtomConnections(eleptr->NumberOfConnections);
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfConnections)
               ReadBinBensonAtomConnections(ptrConnections++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonSecondOrder(XDR *stream, char **eleptrp)
{
     BensonSecondOrder *eleptr;
     eleptr = (BensonSecondOrder *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->CenterAtom));
     xdr_INT(stream,(char **) &(eleptr->NumberOfConnections));

     xdr_pointer(stream,
          (char **) &(eleptr->TableValues),
          BensonSecondThermoTableSize,
                 (xdrproc_t) xdr_BensonSecondThermoTable);
     xdr_array(stream,(char **) &(eleptr->Connections),
             (uint *) &(eleptr->NumberOfConnections),eleptr->NumberOfConnections,
               BensonAtomConnectionsSize,(xdrproc_t) xdr_BensonAtomConnections);
}

extern void *AllocBensonSecondOrder()
{
     return((void *) AllocateBensonSecondOrder);
}

extern CHAR *GetNameBensonSecondOrderTable(BensonSecondOrderTable *str)
{
     return(str->Name);
}

extern INT GetIDBensonSecondOrderTable(BensonSecondOrderTable *str)
{
     return(str->ID);
}

extern BensonSecondOrderTable *CreateBensonSecondOrderTable(BensonSecondOrderTable *newstruct,
                                                     INT id,
                                                     CHAR *name,
                                                     INT  NumberOfTableValues,
                                                     BensonSecondOrder *Values,
                                                     INT  NumberOfTemperatures,
                                                     FLOAT *Temperatures,
                                                     STRING *Reference)
{
BensonSecondOrder *oldValues,*newValues;
FLOAT *oldTemperatures,*newTemperatures;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfTableValues = NumberOfTableValues;
     newstruct->NumberOfTemperatures = NumberOfTemperatures;
     if(Reference != 0)
          {
          newstruct->Reference = AllocateSTRING;
          CopyFullSTRING(newstruct->Reference, Reference);
          }
     else
          newstruct->Reference = 0;

     newstruct->Values = AllocArrayBensonSecondOrder(newstruct->NumberOfTableValues);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfTableValues)
               CopyFullBensonSecondOrder(newValues++, oldValues++);
          }

     newstruct->Temperatures = AllocArrayFLOAT(newstruct->NumberOfTemperatures);
     if(Temperatures != 0)
          {
          oldTemperatures = Temperatures;
          newTemperatures = newstruct->Temperatures;
          LOOPi(newstruct->NumberOfTemperatures)
               CopyFullFLOAT(newTemperatures++, oldTemperatures++);
          }



     return(newstruct);
}


extern void CopyFullBensonSecondOrderTable(BensonSecondOrderTable *newstruct, BensonSecondOrderTable *oldstruct)
{
BensonSecondOrder *oldValues,*newValues;
FLOAT *oldTemperatures,*newTemperatures;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfTableValues = oldstruct->NumberOfTableValues;
     newstruct->NumberOfTemperatures = oldstruct->NumberOfTemperatures;

     if(oldstruct->Reference != 0)
          {
          newstruct->Reference = AllocateSTRING;
          CopyFullSTRING(newstruct->Reference, oldstruct->Reference);
          }
     else
          newstruct->Reference = 0;

     newstruct->Values = AllocArrayBensonSecondOrder(newstruct->NumberOfTableValues);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfTableValues)
               CopyFullBensonSecondOrder(newValues++, oldValues++);
          }

     newstruct->Temperatures = AllocArrayFLOAT(newstruct->NumberOfTemperatures);
     if(oldstruct->Temperatures != 0)
          {
          oldTemperatures = oldstruct->Temperatures;
          newTemperatures = newstruct->Temperatures;
          LOOPi(newstruct->NumberOfTemperatures)
               CopyFullFLOAT(newTemperatures++, oldTemperatures++);
          }


}
extern void PrintBensonSecondOrderTable(BensonSecondOrderTable *eleptr)
{
BensonSecondOrder *ptrValues;
FLOAT *ptrTemperatures;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Table Values:");
     printf("%d\n",eleptr->NumberOfTableValues);
     printf("The number temperatures for heat capacities:");
     printf("%d\n",eleptr->NumberOfTemperatures);

     printf("           Reference:\n");
     PrintSTRING(eleptr->Reference);

     printf("    The table values:\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfTableValues)
               PrintBensonSecondOrder(ptrValues++);
          }


     printf("The set of Temperatures:\n");
     if(eleptr->Temperatures != 0)
          {
          ptrTemperatures = eleptr->Temperatures;
          LOOPi(eleptr->NumberOfTemperatures)
               PrintFLOAT(ptrTemperatures++);
          }


}
extern void FreeBensonSecondOrderTable(BensonSecondOrderTable *eleptr)
{
BensonSecondOrder *ptrValues;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrValues = eleptr->Values;
     LOOPi(eleptr->NumberOfTableValues)
          FreeBensonSecondOrder(ptrValues++);
     Free(eleptr->Values);

     Free(eleptr->Temperatures);

     FreeSTRING(eleptr->Reference);

}
extern void WriteBinBensonSecondOrderTable(BensonSecondOrderTable *eleptr, DbaseLinkedList *file)
{
BensonSecondOrder *ptrValues;
FLOAT *ptrTemperatures;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfTableValues),file);
     WriteBinINT(&(eleptr->NumberOfTemperatures),file);

     WriteBinSTRING(eleptr->Reference,file);

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfTableValues)
               WriteBinBensonSecondOrder(ptrValues++,file);
          }

     if(eleptr->Temperatures != 0)
          {
          ptrTemperatures = eleptr->Temperatures;
          LOOPi(eleptr->NumberOfTemperatures)
               WriteBinFLOAT(ptrTemperatures++,file);
          }

}
extern INT ReadBinBensonSecondOrderTable(BensonSecondOrderTable *eleptr,DbaseLinkedList *file)
     {
BensonSecondOrder *ptrValues;
FLOAT *ptrTemperatures;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfTableValues),file);
     ReadBinINT(&(eleptr->NumberOfTemperatures),file);

     eleptr->Reference = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Reference,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reference);
           eleptr->Reference = 0;
           }

          eleptr->Values = AllocArrayBensonSecondOrder(eleptr->NumberOfTableValues);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfTableValues)
               ReadBinBensonSecondOrder(ptrValues++,file);

          eleptr->Temperatures = AllocArrayFLOAT(eleptr->NumberOfTemperatures);
          ptrTemperatures = eleptr->Temperatures;
          LOOPi(eleptr->NumberOfTemperatures)
               ReadBinFLOAT(ptrTemperatures++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonSecondOrderTable(XDR *stream, char **eleptrp)
{
     BensonSecondOrderTable *eleptr;
     eleptr = (BensonSecondOrderTable *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTableValues));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTemperatures));

     xdr_pointer(stream,
          (char **) &(eleptr->Reference),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfTableValues),eleptr->NumberOfTableValues,
               BensonSecondOrderSize,(xdrproc_t) xdr_BensonSecondOrder);
     xdr_array(stream,(char **) &(eleptr->Temperatures),
             (uint *) &(eleptr->NumberOfTemperatures),eleptr->NumberOfTemperatures,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocBensonSecondOrderTable()
{
     return((void *) AllocateBensonSecondOrderTable);
}

extern CHAR *GetNameSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *str)
{
     return(str->Name);
}

extern INT GetIDSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *str)
{
     return(str->ID);
}

extern SetOfBenson2ndOrderTables *CreateSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *newstruct,
INT id,
CHAR *name,
INT  NumberOfTables,
BensonSecondOrderTable *Tables)
{
BensonSecondOrderTable *oldTables,*newTables;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfTables = NumberOfTables;

     newstruct->Tables = AllocArrayBensonSecondOrderTable(newstruct->NumberOfTables);
     if(Tables != 0)
          {
          oldTables = Tables;
          newTables = newstruct->Tables;
          LOOPi(newstruct->NumberOfTables)
               CopyFullBensonSecondOrderTable(newTables++, oldTables++);
          }



     return(newstruct);
}


extern void CopyFullSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *newstruct, SetOfBenson2ndOrderTables *oldstruct)
{
BensonSecondOrderTable *oldTables,*newTables;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfTables = oldstruct->NumberOfTables;


     newstruct->Tables = AllocArrayBensonSecondOrderTable(newstruct->NumberOfTables);
     if(oldstruct->Tables != 0)
          {
          oldTables = oldstruct->Tables;
          newTables = newstruct->Tables;
          LOOPi(newstruct->NumberOfTables)
               CopyFullBensonSecondOrderTable(newTables++, oldTables++);
          }


}
extern void PrintSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr)
{
BensonSecondOrderTable *ptrTables;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of tables:");
     printf("%d\n",eleptr->NumberOfTables);

     printf("   The set of tables:\n");
     if(eleptr->Tables != 0)
          {
          ptrTables = eleptr->Tables;
          LOOPi(eleptr->NumberOfTables)
               PrintBensonSecondOrderTable(ptrTables++);
          }


}
extern void FreeSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr)
{
BensonSecondOrderTable *ptrTables;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrTables = eleptr->Tables;
     LOOPi(eleptr->NumberOfTables)
          FreeBensonSecondOrderTable(ptrTables++);
     Free(eleptr->Tables);

}
extern void WriteBinSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr, DbaseLinkedList *file)
{
BensonSecondOrderTable *ptrTables;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfTables),file);

     if(eleptr->Tables != 0)
          {
          ptrTables = eleptr->Tables;
          LOOPi(eleptr->NumberOfTables)
               WriteBinBensonSecondOrderTable(ptrTables++,file);
          }

}
extern INT ReadBinSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr,DbaseLinkedList *file)
     {
BensonSecondOrderTable *ptrTables;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfTables),file);

          eleptr->Tables = AllocArrayBensonSecondOrderTable(eleptr->NumberOfTables);
          ptrTables = eleptr->Tables;
          LOOPi(eleptr->NumberOfTables)
               ReadBinBensonSecondOrderTable(ptrTables++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfBenson2ndOrderTables(XDR *stream, char **eleptrp)
{
     SetOfBenson2ndOrderTables *eleptr;
     eleptr = (SetOfBenson2ndOrderTables *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTables));

     xdr_array(stream,(char **) &(eleptr->Tables),
             (uint *) &(eleptr->NumberOfTables),eleptr->NumberOfTables,
               BensonSecondOrderTableSize,(xdrproc_t) xdr_BensonSecondOrderTable);
}

extern void *AllocSetOfBenson2ndOrderTables()
{
     return((void *) AllocateSetOfBenson2ndOrderTables);
}

extern CHAR *GetNameBensonTranslationPair(BensonTranslationPair *str)
{
     return(str->Name);
}

extern INT GetIDBensonTranslationPair(BensonTranslationPair *str)
{
     return(str->ID);
}

extern BensonTranslationPair *CreateBensonTranslationPair(BensonTranslationPair *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Valence,
                                                   STRING *AtomName)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Valence = Valence;
     if(AtomName != 0)
          {
          newstruct->AtomName = AllocateSTRING;
          CopyFullSTRING(newstruct->AtomName, AtomName);
          }
     else
          newstruct->AtomName = 0;



     return(newstruct);
}


extern void CopyFullBensonTranslationPair(BensonTranslationPair *newstruct, BensonTranslationPair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Valence = oldstruct->Valence;

     if(oldstruct->AtomName != 0)
          {
          newstruct->AtomName = AllocateSTRING;
          CopyFullSTRING(newstruct->AtomName, oldstruct->AtomName);
          }
     else
          newstruct->AtomName = 0;


}
extern void PrintBensonTranslationPair(BensonTranslationPair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("   The Valence Value:");
     printf("%d\n",eleptr->Valence);

     printf("            The Name:\n");
     PrintSTRING(eleptr->AtomName);

}
extern void FreeBensonTranslationPair(BensonTranslationPair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->AtomName);

}
extern void WriteBinBensonTranslationPair(BensonTranslationPair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Valence),file);

     WriteBinSTRING(eleptr->AtomName,file);

}
extern INT ReadBinBensonTranslationPair(BensonTranslationPair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Valence),file);

     eleptr->AtomName = AllocateSTRING;
     if(ReadBinSTRING(eleptr->AtomName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AtomName);
           eleptr->AtomName = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BensonTranslationPair(XDR *stream, char **eleptrp)
{
     BensonTranslationPair *eleptr;
     eleptr = (BensonTranslationPair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Valence));

     xdr_pointer(stream,
          (char **) &(eleptr->AtomName),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocBensonTranslationPair()
{
     return((void *) AllocateBensonTranslationPair);
}

extern CHAR *GetNameSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *str)
{
     return(str->Name);
}

extern INT GetIDSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *str)
{
     return(str->ID);
}

extern SetOfBensonAtomTranslationPairs *CreateSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *newstruct,
INT id,
CHAR *name,
INT  NumberOfPairs,
BensonTranslationPair *Pairs)
{
BensonTranslationPair *oldPairs,*newPairs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPairs = NumberOfPairs;

     newstruct->Pairs = AllocArrayBensonTranslationPair(newstruct->NumberOfPairs);
     if(Pairs != 0)
          {
          oldPairs = Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullBensonTranslationPair(newPairs++, oldPairs++);
          }



     return(newstruct);
}


extern void CopyFullSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *newstruct, SetOfBensonAtomTranslationPairs *oldstruct)
{
BensonTranslationPair *oldPairs,*newPairs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPairs = oldstruct->NumberOfPairs;


     newstruct->Pairs = AllocArrayBensonTranslationPair(newstruct->NumberOfPairs);
     if(oldstruct->Pairs != 0)
          {
          oldPairs = oldstruct->Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullBensonTranslationPair(newPairs++, oldPairs++);
          }


}
extern void PrintSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr)
{
BensonTranslationPair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of pairs:");
     printf("%d\n",eleptr->NumberOfPairs);

     printf("The set of Translation Pairs:\n");
     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               PrintBensonTranslationPair(ptrPairs++);
          }


}
extern void FreeSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr)
{
BensonTranslationPair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPairs = eleptr->Pairs;
     LOOPi(eleptr->NumberOfPairs)
          FreeBensonTranslationPair(ptrPairs++);
     Free(eleptr->Pairs);

}
extern void WriteBinSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr, DbaseLinkedList *file)
{
BensonTranslationPair *ptrPairs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPairs),file);

     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               WriteBinBensonTranslationPair(ptrPairs++,file);
          }

}
extern INT ReadBinSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr,DbaseLinkedList *file)
     {
BensonTranslationPair *ptrPairs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPairs),file);

          eleptr->Pairs = AllocArrayBensonTranslationPair(eleptr->NumberOfPairs);
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               ReadBinBensonTranslationPair(ptrPairs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfBensonAtomTranslationPairs(XDR *stream, char **eleptrp)
{
     SetOfBensonAtomTranslationPairs *eleptr;
     eleptr = (SetOfBensonAtomTranslationPairs *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPairs));

     xdr_array(stream,(char **) &(eleptr->Pairs),
             (uint *) &(eleptr->NumberOfPairs),eleptr->NumberOfPairs,
               BensonTranslationPairSize,(xdrproc_t) xdr_BensonTranslationPair);
}

extern void *AllocSetOfBensonAtomTranslationPairs()
{
     return((void *) AllocateSetOfBensonAtomTranslationPairs);
}
