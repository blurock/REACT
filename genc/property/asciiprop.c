
extern CHAR *GetNameASCIIProperty(ASCIIProperty *str)
{
     return(str->Name);
}

extern INT GetIDASCIIProperty(ASCIIProperty *str)
{
     return(str->ID);
}

extern ASCIIProperty *CreateASCIIProperty(ASCIIProperty *newstruct,
                                   INT id,
                                   CHAR *name,
                                   STRING *PropertyValue)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(PropertyValue != 0)
          {
          newstruct->PropertyValue = AllocateSTRING;
          CopyFullSTRING(newstruct->PropertyValue, PropertyValue);
          }
     else
          newstruct->PropertyValue = 0;



     return(newstruct);
}


extern void CopyFullASCIIProperty(ASCIIProperty *newstruct, ASCIIProperty *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->PropertyValue != 0)
          {
          newstruct->PropertyValue = AllocateSTRING;
          CopyFullSTRING(newstruct->PropertyValue, oldstruct->PropertyValue);
          }
     else
          newstruct->PropertyValue = 0;


}
extern void PrintASCIIProperty(ASCIIProperty *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("  The property value:\n");
     PrintSTRING(eleptr->PropertyValue);

}
extern void FreeASCIIProperty(ASCIIProperty *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->PropertyValue);

}
extern void WriteBinASCIIProperty(ASCIIProperty *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->PropertyValue,file);

}
extern INT ReadBinASCIIProperty(ASCIIProperty *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->PropertyValue = AllocateSTRING;
     if(ReadBinSTRING(eleptr->PropertyValue,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropertyValue);
           eleptr->PropertyValue = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ASCIIProperty(XDR *stream, char **eleptrp)
{
     ASCIIProperty *eleptr;
     eleptr = (ASCIIProperty *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->PropertyValue),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
}

extern void *AllocASCIIProperty()
{
     return((void *) AllocateASCIIProperty);
}

extern CHAR *GetNameASCIIProperties(ASCIIProperties *str)
{
     return(str->Name);
}

extern INT GetIDASCIIProperties(ASCIIProperties *str)
{
     return(str->ID);
}

extern ASCIIProperties *CreateASCIIProperties(ASCIIProperties *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfProperties,
                                       ASCIIProperty *Properties)
{
ASCIIProperty *oldProperties,*newProperties;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfProperties = NumberOfProperties;

     newstruct->Properties = AllocArrayASCIIProperty(newstruct->NumberOfProperties);
     if(Properties != 0)
          {
          oldProperties = Properties;
          newProperties = newstruct->Properties;
          LOOPi(newstruct->NumberOfProperties)
               CopyFullASCIIProperty(newProperties++, oldProperties++);
          }



     return(newstruct);
}


extern void CopyFullASCIIProperties(ASCIIProperties *newstruct, ASCIIProperties *oldstruct)
{
ASCIIProperty *oldProperties,*newProperties;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfProperties = oldstruct->NumberOfProperties;


     newstruct->Properties = AllocArrayASCIIProperty(newstruct->NumberOfProperties);
     if(oldstruct->Properties != 0)
          {
          oldProperties = oldstruct->Properties;
          newProperties = newstruct->Properties;
          LOOPi(newstruct->NumberOfProperties)
               CopyFullASCIIProperty(newProperties++, oldProperties++);
          }


}
extern void PrintASCIIProperties(ASCIIProperties *eleptr)
{
ASCIIProperty *ptrProperties;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of properties listed:");
     printf("%d\n",eleptr->NumberOfProperties);

     printf("The set of propertties (as ASCII text):\n");
     if(eleptr->Properties != 0)
          {
          ptrProperties = eleptr->Properties;
          LOOPi(eleptr->NumberOfProperties)
               PrintASCIIProperty(ptrProperties++);
          }


}
extern void FreeASCIIProperties(ASCIIProperties *eleptr)
{
ASCIIProperty *ptrProperties;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrProperties = eleptr->Properties;
     LOOPi(eleptr->NumberOfProperties)
          FreeASCIIProperty(ptrProperties++);
     Free(eleptr->Properties);

}
extern void WriteBinASCIIProperties(ASCIIProperties *eleptr, DbaseLinkedList *file)
{
ASCIIProperty *ptrProperties;
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
               WriteBinASCIIProperty(ptrProperties++,file);
          }

}
extern INT ReadBinASCIIProperties(ASCIIProperties *eleptr,DbaseLinkedList *file)
     {
ASCIIProperty *ptrProperties;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfProperties),file);

          eleptr->Properties = AllocArrayASCIIProperty(eleptr->NumberOfProperties);
          ptrProperties = eleptr->Properties;
          LOOPi(eleptr->NumberOfProperties)
               ReadBinASCIIProperty(ptrProperties++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ASCIIProperties(XDR *stream, char **eleptrp)
{
     ASCIIProperties *eleptr;
     eleptr = (ASCIIProperties *) eleptrp;
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
               ASCIIPropertySize,(xdrproc_t) xdr_ASCIIProperty);
}

extern void *AllocASCIIProperties()
{
     return((void *) AllocateASCIIProperties);
}
