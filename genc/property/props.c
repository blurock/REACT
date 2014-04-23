
extern CHAR *GetNameGenPropValue(GenPropValue *str)
{
     return(str->Name);
}

extern INT GetIDGenPropValue(GenPropValue *str)
{
     return(str->ID);
}

extern GenPropValue *CreateGenPropValue(GenPropValue *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  SrcType,
                                 INT  Confidence,
                                 INT  NumberOfBytes,
                                 CHAR *Value,
                                 STRING *Reference,
                                 STRING *Text)
{
CHAR *oldValue,*newValue;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->SrcType = SrcType;
     newstruct->Confidence = Confidence;
     newstruct->NumberOfBytes = NumberOfBytes;
     if(Reference != 0)
          {
          newstruct->Reference = AllocateSTRING;
          CopyFullSTRING(newstruct->Reference, Reference);
          }
     else
          newstruct->Reference = 0;
     if(Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, Text);
          }
     else
          newstruct->Text = 0;

     newstruct->Value = AllocArrayCHAR(newstruct->NumberOfBytes);
     if(Value != 0)
          {
          oldValue = Value;
          newValue = newstruct->Value;
          LOOPi(newstruct->NumberOfBytes)
               CopyFullCHAR(newValue++, oldValue++);
          }



     return(newstruct);
}


extern void CopyFullGenPropValue(GenPropValue *newstruct, GenPropValue *oldstruct)
{
CHAR *oldValue,*newValue;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->SrcType = oldstruct->SrcType;
     newstruct->Confidence = oldstruct->Confidence;
     newstruct->NumberOfBytes = oldstruct->NumberOfBytes;

     if(oldstruct->Reference != 0)
          {
          newstruct->Reference = AllocateSTRING;
          CopyFullSTRING(newstruct->Reference, oldstruct->Reference);
          }
     else
          newstruct->Reference = 0;
     if(oldstruct->Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, oldstruct->Text);
          }
     else
          newstruct->Text = 0;

     newstruct->Value = AllocArrayCHAR(newstruct->NumberOfBytes);
     if(oldstruct->Value != 0)
          {
          oldValue = oldstruct->Value;
          newValue = newstruct->Value;
          LOOPi(newstruct->NumberOfBytes)
               CopyFullCHAR(newValue++, oldValue++);
          }


}
extern void PrintGenPropValue(GenPropValue *eleptr)
{
CHAR *ptrValue;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The general source type of this particular value:");
     printf("%d\n",eleptr->SrcType);
     printf("The confidence of this particular value (compared with others):");
     printf("%d\n",eleptr->Confidence);
     printf("The number of bytes needed to store the value:");
     printf("%d\n",eleptr->NumberOfBytes);

     printf("A text value for the lterature reference:\n");
     PrintSTRING(eleptr->Reference);

     printf("A text value concerning this particular value:\n");
     PrintSTRING(eleptr->Text);

     printf("The set of bytes representing the value:\n");
     if(eleptr->Value != 0)
          {
          ptrValue = eleptr->Value;
          LOOPi(eleptr->NumberOfBytes)
               PrintCHAR(ptrValue++);
          }


}
extern void FreeGenPropValue(GenPropValue *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Value);

     FreeSTRING(eleptr->Reference);

     FreeSTRING(eleptr->Text);

}
extern void WriteBinGenPropValue(GenPropValue *eleptr, DbaseLinkedList *file)
{
CHAR *ptrValue;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->SrcType),file);
     WriteBinINT(&(eleptr->Confidence),file);
     WriteBinINT(&(eleptr->NumberOfBytes),file);

     WriteBinSTRING(eleptr->Reference,file);

     WriteBinSTRING(eleptr->Text,file);

     if(eleptr->Value != 0)
          {
          ptrValue = eleptr->Value;
          LOOPi(eleptr->NumberOfBytes)
               WriteBinCHAR(ptrValue++,file);
          }

}
extern INT ReadBinGenPropValue(GenPropValue *eleptr,DbaseLinkedList *file)
     {
CHAR *ptrValue;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->SrcType),file);
     ReadBinINT(&(eleptr->Confidence),file);
     ReadBinINT(&(eleptr->NumberOfBytes),file);

     eleptr->Reference = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Reference,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reference);
           eleptr->Reference = 0;
           }

     eleptr->Text = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Text,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Text);
           eleptr->Text = 0;
           }

          eleptr->Value = AllocArrayCHAR(eleptr->NumberOfBytes);
          ptrValue = eleptr->Value;
          LOOPi(eleptr->NumberOfBytes)
               ReadBinCHAR(ptrValue++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_GenPropValue(XDR *stream, char **eleptrp)
{
     GenPropValue *eleptr;
     eleptr = (GenPropValue *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->SrcType));
     xdr_INT(stream,(char **) &(eleptr->Confidence));
     xdr_INT(stream,(char **) &(eleptr->NumberOfBytes));

     xdr_pointer(stream,
          (char **) &(eleptr->Reference),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Text),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_array(stream,(char **) &(eleptr->Value),
             (uint *) &(eleptr->NumberOfBytes),eleptr->NumberOfBytes,
               CHARSize,(xdrproc_t) xdr_CHAR);
}

extern void *AllocGenPropValue()
{
     return((void *) AllocateGenPropValue);
}

extern CHAR *GetNamePropertyValues(PropertyValues *str)
{
     return(str->Name);
}

extern INT GetIDPropertyValues(PropertyValues *str)
{
     return(str->ID);
}

extern PropertyValues *CreatePropertyValues(PropertyValues *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfAllocatedValues,
                                     INT  NumberOfValues,
                                     GenPropValue *Values,
                                     INT  Type,
                                     STRING *Text)
{
GenPropValue *oldValues,*newValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAllocatedValues = NumberOfAllocatedValues;
     newstruct->NumberOfValues = NumberOfValues;
     newstruct->Type = Type;
     if(Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, Text);
          }
     else
          newstruct->Text = 0;

     newstruct->Values = AllocArrayGenPropValue(newstruct->NumberOfValues);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullGenPropValue(newValues++, oldValues++);
          }



     return(newstruct);
}


extern void CopyFullPropertyValues(PropertyValues *newstruct, PropertyValues *oldstruct)
{
GenPropValue *oldValues,*newValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAllocatedValues = oldstruct->NumberOfAllocatedValues;
     newstruct->NumberOfValues = oldstruct->NumberOfValues;
     newstruct->Type = oldstruct->Type;

     if(oldstruct->Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, oldstruct->Text);
          }
     else
          newstruct->Text = 0;

     newstruct->Values = AllocArrayGenPropValue(newstruct->NumberOfValues);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullGenPropValue(newValues++, oldValues++);
          }


}
extern void PrintPropertyValues(PropertyValues *eleptr)
{
GenPropValue *ptrValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Allocated Values:");
     printf("%d\n",eleptr->NumberOfAllocatedValues);
     printf("The number of different values for this property:");
     printf("%d\n",eleptr->NumberOfValues);
     printf("The property type (refering to the PropertyType structure):");
     printf("%d\n",eleptr->Type);

     printf("A string text explanation of the property:\n");
     PrintSTRING(eleptr->Text);

     printf("The set of property values:\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               PrintGenPropValue(ptrValues++);
          }


}
extern void FreePropertyValues(PropertyValues *eleptr)
{
GenPropValue *ptrValues;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrValues = eleptr->Values;
     LOOPi(eleptr->NumberOfValues)
          FreeGenPropValue(ptrValues++);
     Free(eleptr->Values);

     FreeSTRING(eleptr->Text);

}
extern void WriteBinPropertyValues(PropertyValues *eleptr, DbaseLinkedList *file)
{
GenPropValue *ptrValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAllocatedValues),file);
     WriteBinINT(&(eleptr->NumberOfValues),file);
     WriteBinINT(&(eleptr->Type),file);

     WriteBinSTRING(eleptr->Text,file);

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               WriteBinGenPropValue(ptrValues++,file);
          }

}
extern INT ReadBinPropertyValues(PropertyValues *eleptr,DbaseLinkedList *file)
     {
GenPropValue *ptrValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAllocatedValues),file);
     ReadBinINT(&(eleptr->NumberOfValues),file);
     ReadBinINT(&(eleptr->Type),file);

     eleptr->Text = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Text,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Text);
           eleptr->Text = 0;
           }

          eleptr->Values = AllocArrayGenPropValue(eleptr->NumberOfValues);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               ReadBinGenPropValue(ptrValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_PropertyValues(XDR *stream, char **eleptrp)
{
     PropertyValues *eleptr;
     eleptr = (PropertyValues *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAllocatedValues));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValues));
     xdr_INT(stream,(char **) &(eleptr->Type));

     xdr_pointer(stream,
          (char **) &(eleptr->Text),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               GenPropValueSize,(xdrproc_t) xdr_GenPropValue);
}

extern void *AllocPropertyValues()
{
     return((void *) AllocatePropertyValues);
}

extern CHAR *GetNameSetOfPropertyValues(SetOfPropertyValues *str)
{
     return(str->Name);
}

extern INT GetIDSetOfPropertyValues(SetOfPropertyValues *str)
{
     return(str->ID);
}

extern SetOfPropertyValues *CreateSetOfPropertyValues(SetOfPropertyValues *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfProperties,
                                               PropertyValues *Properties)
{
PropertyValues *oldProperties,*newProperties;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfProperties = NumberOfProperties;

     newstruct->Properties = AllocArrayPropertyValues(newstruct->NumberOfProperties);
     if(Properties != 0)
          {
          oldProperties = Properties;
          newProperties = newstruct->Properties;
          LOOPi(newstruct->NumberOfProperties)
               CopyFullPropertyValues(newProperties++, oldProperties++);
          }



     return(newstruct);
}


extern void CopyFullSetOfPropertyValues(SetOfPropertyValues *newstruct, SetOfPropertyValues *oldstruct)
{
PropertyValues *oldProperties,*newProperties;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfProperties = oldstruct->NumberOfProperties;


     newstruct->Properties = AllocArrayPropertyValues(newstruct->NumberOfProperties);
     if(oldstruct->Properties != 0)
          {
          oldProperties = oldstruct->Properties;
          newProperties = newstruct->Properties;
          LOOPi(newstruct->NumberOfProperties)
               CopyFullPropertyValues(newProperties++, oldProperties++);
          }


}
extern void PrintSetOfPropertyValues(SetOfPropertyValues *eleptr)
{
PropertyValues *ptrProperties;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of property values stored.:");
     printf("%d\n",eleptr->NumberOfProperties);

     printf("The set of property values:\n");
     if(eleptr->Properties != 0)
          {
          ptrProperties = eleptr->Properties;
          LOOPi(eleptr->NumberOfProperties)
               PrintPropertyValues(ptrProperties++);
          }


}
extern void FreeSetOfPropertyValues(SetOfPropertyValues *eleptr)
{
PropertyValues *ptrProperties;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrProperties = eleptr->Properties;
     LOOPi(eleptr->NumberOfProperties)
          FreePropertyValues(ptrProperties++);
     Free(eleptr->Properties);

}
extern void WriteBinSetOfPropertyValues(SetOfPropertyValues *eleptr, DbaseLinkedList *file)
{
PropertyValues *ptrProperties;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfProperties),file);

     if(eleptr->Properties != 0)
          {
          ptrProperties = eleptr->Properties;
          LOOPi(eleptr->NumberOfProperties)
               WriteBinPropertyValues(ptrProperties++,file);
          }

}
extern INT ReadBinSetOfPropertyValues(SetOfPropertyValues *eleptr,DbaseLinkedList *file)
     {
PropertyValues *ptrProperties;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfProperties),file);

          eleptr->Properties = AllocArrayPropertyValues(eleptr->NumberOfProperties);
          ptrProperties = eleptr->Properties;
          LOOPi(eleptr->NumberOfProperties)
               ReadBinPropertyValues(ptrProperties++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfPropertyValues(XDR *stream, char **eleptrp)
{
     SetOfPropertyValues *eleptr;
     eleptr = (SetOfPropertyValues *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfProperties));

     xdr_array(stream,(char **) &(eleptr->Properties),
             (uint *) &(eleptr->NumberOfProperties),eleptr->NumberOfProperties,
               PropertyValuesSize,(xdrproc_t) xdr_PropertyValues);
}

extern void *AllocSetOfPropertyValues()
{
     return((void *) AllocateSetOfPropertyValues);
}

extern CHAR *GetNamePropertyType(PropertyType *str)
{
     return(str->Name);
}

extern INT GetIDPropertyType(PropertyType *str)
{
     return(str->ID);
}

extern PropertyType *CreatePropertyType(PropertyType *newstruct,
                                 INT id,
                                 CHAR *name,
                                 GenPropValue *(*CalculateValue)(),
                                 void  (*FreeValue)(),
                                 INT  (*ReadBinValue)(),
                                 void  (*WriteBinValue)(),
                                 void  (*TranslateString)(),
                                 void  (*PrintSingleValue)(),
                                 CHAR *(*ValueOnLine)(),
                                 INT  MinimumFieldLength,
                                 STRING *Text)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->FreeValue = FreeValue;
     newstruct->ReadBinValue = ReadBinValue;
     newstruct->WriteBinValue = WriteBinValue;
     newstruct->TranslateString = TranslateString;
     newstruct->PrintSingleValue = PrintSingleValue;
     newstruct->MinimumFieldLength = MinimumFieldLength;
     if(Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, Text);
          }
     else
          newstruct->Text = 0;



     return(newstruct);
}


extern void CopyFullPropertyType(PropertyType *newstruct, PropertyType *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->FreeValue = oldstruct->FreeValue;
     newstruct->ReadBinValue = oldstruct->ReadBinValue;
     newstruct->WriteBinValue = oldstruct->WriteBinValue;
     newstruct->TranslateString = oldstruct->TranslateString;
     newstruct->PrintSingleValue = oldstruct->PrintSingleValue;
     newstruct->MinimumFieldLength = oldstruct->MinimumFieldLength;

     if(oldstruct->Text != 0)
          {
          newstruct->Text = AllocateSTRING;
          CopyFullSTRING(newstruct->Text, oldstruct->Text);
          }
     else
          newstruct->Text = 0;


}
extern void PrintPropertyType(PropertyType *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The minimum size of the one line field:");
     printf("%d\n",eleptr->MinimumFieldLength);

     printf("A text string explaining property:\n");
     PrintSTRING(eleptr->Text);

}
extern void FreePropertyType(PropertyType *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->Text);

}
extern void WriteBinPropertyType(PropertyType *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MinimumFieldLength),file);

     WriteBinSTRING(eleptr->Text,file);

}
extern INT ReadBinPropertyType(PropertyType *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MinimumFieldLength),file);

     eleptr->Text = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Text,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Text);
           eleptr->Text = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_PropertyType(XDR *stream, char **eleptrp)
{
     PropertyType *eleptr;
     eleptr = (PropertyType *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MinimumFieldLength));

     xdr_pointer(stream,
          (char **) &(eleptr->Text),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocPropertyType()
{
     return((void *) AllocatePropertyType);
}

extern CHAR *GetNameSetOfPropertyTypes(SetOfPropertyTypes *str)
{
     return(str->Name);
}

extern INT GetIDSetOfPropertyTypes(SetOfPropertyTypes *str)
{
     return(str->ID);
}

extern SetOfPropertyTypes *CreateSetOfPropertyTypes(SetOfPropertyTypes *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfPropertyTypes,
                                             PropertyType *Types)
{
PropertyType *oldTypes,*newTypes;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPropertyTypes = NumberOfPropertyTypes;

     newstruct->Types = AllocArrayPropertyType(newstruct->NumberOfPropertyTypes);
     if(Types != 0)
          {
          oldTypes = Types;
          newTypes = newstruct->Types;
          LOOPi(newstruct->NumberOfPropertyTypes)
               CopyFullPropertyType(newTypes++, oldTypes++);
          }



     return(newstruct);
}


extern void CopyFullSetOfPropertyTypes(SetOfPropertyTypes *newstruct, SetOfPropertyTypes *oldstruct)
{
PropertyType *oldTypes,*newTypes;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPropertyTypes = oldstruct->NumberOfPropertyTypes;


     newstruct->Types = AllocArrayPropertyType(newstruct->NumberOfPropertyTypes);
     if(oldstruct->Types != 0)
          {
          oldTypes = oldstruct->Types;
          newTypes = newstruct->Types;
          LOOPi(newstruct->NumberOfPropertyTypes)
               CopyFullPropertyType(newTypes++, oldTypes++);
          }


}
extern void PrintSetOfPropertyTypes(SetOfPropertyTypes *eleptr)
{
PropertyType *ptrTypes;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of property types specified:");
     printf("%d\n",eleptr->NumberOfPropertyTypes);

     printf("The set of property types:\n");
     if(eleptr->Types != 0)
          {
          ptrTypes = eleptr->Types;
          LOOPi(eleptr->NumberOfPropertyTypes)
               PrintPropertyType(ptrTypes++);
          }


}
extern void FreeSetOfPropertyTypes(SetOfPropertyTypes *eleptr)
{
PropertyType *ptrTypes;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrTypes = eleptr->Types;
     LOOPi(eleptr->NumberOfPropertyTypes)
          FreePropertyType(ptrTypes++);
     Free(eleptr->Types);

}
extern void WriteBinSetOfPropertyTypes(SetOfPropertyTypes *eleptr, DbaseLinkedList *file)
{
PropertyType *ptrTypes;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPropertyTypes),file);

     if(eleptr->Types != 0)
          {
          ptrTypes = eleptr->Types;
          LOOPi(eleptr->NumberOfPropertyTypes)
               WriteBinPropertyType(ptrTypes++,file);
          }

}
extern INT ReadBinSetOfPropertyTypes(SetOfPropertyTypes *eleptr,DbaseLinkedList *file)
     {
PropertyType *ptrTypes;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPropertyTypes),file);

          eleptr->Types = AllocArrayPropertyType(eleptr->NumberOfPropertyTypes);
          ptrTypes = eleptr->Types;
          LOOPi(eleptr->NumberOfPropertyTypes)
               ReadBinPropertyType(ptrTypes++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfPropertyTypes(XDR *stream, char **eleptrp)
{
     SetOfPropertyTypes *eleptr;
     eleptr = (SetOfPropertyTypes *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPropertyTypes));

     xdr_array(stream,(char **) &(eleptr->Types),
             (uint *) &(eleptr->NumberOfPropertyTypes),eleptr->NumberOfPropertyTypes,
               PropertyTypeSize,(xdrproc_t) xdr_PropertyType);
}

extern void *AllocSetOfPropertyTypes()
{
     return((void *) AllocateSetOfPropertyTypes);
}

extern CHAR *GetNameValueTypeIntVector(ValueTypeIntVector *str)
{
     return(str->Name);
}

extern INT GetIDValueTypeIntVector(ValueTypeIntVector *str)
{
     return(str->ID);
}

extern ValueTypeIntVector *CreateValueTypeIntVector(ValueTypeIntVector *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfValues,
                                             INT *Values)
{
INT *oldValues,*newValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfValues = NumberOfValues;

     newstruct->Values = AllocArrayINT(newstruct->NumberOfValues);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullINT(newValues++, oldValues++);
          }



     return(newstruct);
}


extern void CopyFullValueTypeIntVector(ValueTypeIntVector *newstruct, ValueTypeIntVector *oldstruct)
{
INT *oldValues,*newValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfValues = oldstruct->NumberOfValues;


     newstruct->Values = AllocArrayINT(newstruct->NumberOfValues);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullINT(newValues++, oldValues++);
          }


}
extern void PrintValueTypeIntVector(ValueTypeIntVector *eleptr)
{
INT *ptrValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of values in the vector:");
     printf("%d\n",eleptr->NumberOfValues);

     printf("The set of integer values:\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               PrintINT(ptrValues++);
          }


}
extern void FreeValueTypeIntVector(ValueTypeIntVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Values);

}
extern void WriteBinValueTypeIntVector(ValueTypeIntVector *eleptr, DbaseLinkedList *file)
{
INT *ptrValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfValues),file);

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               WriteBinINT(ptrValues++,file);
          }

}
extern INT ReadBinValueTypeIntVector(ValueTypeIntVector *eleptr,DbaseLinkedList *file)
     {
INT *ptrValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfValues),file);

          eleptr->Values = AllocArrayINT(eleptr->NumberOfValues);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               ReadBinINT(ptrValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ValueTypeIntVector(XDR *stream, char **eleptrp)
{
     ValueTypeIntVector *eleptr;
     eleptr = (ValueTypeIntVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValues));

     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocValueTypeIntVector()
{
     return((void *) AllocateValueTypeIntVector);
}

extern CHAR *GetNameValueTypeFltVector(ValueTypeFltVector *str)
{
     return(str->Name);
}

extern INT GetIDValueTypeFltVector(ValueTypeFltVector *str)
{
     return(str->ID);
}

extern ValueTypeFltVector *CreateValueTypeFltVector(ValueTypeFltVector *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfValues,
                                             FLOAT *Values)
{
FLOAT *oldValues,*newValues;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfValues = NumberOfValues;

     newstruct->Values = AllocArrayFLOAT(newstruct->NumberOfValues);
     if(Values != 0)
          {
          oldValues = Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullFLOAT(newValues++, oldValues++);
          }



     return(newstruct);
}


extern void CopyFullValueTypeFltVector(ValueTypeFltVector *newstruct, ValueTypeFltVector *oldstruct)
{
FLOAT *oldValues,*newValues;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfValues = oldstruct->NumberOfValues;


     newstruct->Values = AllocArrayFLOAT(newstruct->NumberOfValues);
     if(oldstruct->Values != 0)
          {
          oldValues = oldstruct->Values;
          newValues = newstruct->Values;
          LOOPi(newstruct->NumberOfValues)
               CopyFullFLOAT(newValues++, oldValues++);
          }


}
extern void PrintValueTypeFltVector(ValueTypeFltVector *eleptr)
{
FLOAT *ptrValues;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of values in the vector:");
     printf("%d\n",eleptr->NumberOfValues);

     printf("The set of integer values:\n");
     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               PrintFLOAT(ptrValues++);
          }


}
extern void FreeValueTypeFltVector(ValueTypeFltVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Values);

}
extern void WriteBinValueTypeFltVector(ValueTypeFltVector *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrValues;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfValues),file);

     if(eleptr->Values != 0)
          {
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               WriteBinFLOAT(ptrValues++,file);
          }

}
extern INT ReadBinValueTypeFltVector(ValueTypeFltVector *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrValues;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfValues),file);

          eleptr->Values = AllocArrayFLOAT(eleptr->NumberOfValues);
          ptrValues = eleptr->Values;
          LOOPi(eleptr->NumberOfValues)
               ReadBinFLOAT(ptrValues++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ValueTypeFltVector(XDR *stream, char **eleptrp)
{
     ValueTypeFltVector *eleptr;
     eleptr = (ValueTypeFltVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValues));

     xdr_array(stream,(char **) &(eleptr->Values),
             (uint *) &(eleptr->NumberOfValues),eleptr->NumberOfValues,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocValueTypeFltVector()
{
     return((void *) AllocateValueTypeFltVector);
}
