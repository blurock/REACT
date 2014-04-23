/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:100:GenPropValue

                  SrcType --(INT) The general source type of this particular value
               Confidence --(INT) The confidence of this particular value (compared with others)
            NumberOfBytes --(INT) The number of bytes needed to store the value
                    Value --(CHAR) The set of bytes representing the value
                Reference --(STRING) A text value for the lterature reference
                     Text --(STRING) A text value concerning this particular value
*/
typedef struct genpropvalue GenPropValue;
struct genpropvalue {
     INT ID;
     CHAR *Name;
     INT  SrcType;
     INT  Confidence;
     INT  NumberOfBytes;
     CHAR *Value;
     STRING *Reference;
     STRING *Text;
     };
#define GenPropValueSize sizeof(GenPropValue)
#define AllocateGenPropValue (GenPropValue *) Malloc(GenPropValueSize)
#define AllocArrayGenPropValue(n) (GenPropValue *) Calloc(n,GenPropValueSize)
#define GenPropValuePntrSize sizeof(GenPropValue **)
#define AllocPntrArrayGenPropValue(n) (GenPropValue **) Calloc(n,GenPropValuePntrSize)
#define SingCopyGenPropValue(out,in) memcpy(out,in,GenPropValueSize)
extern GenPropValue *CreateGenPropValue(GenPropValue *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  SrcType,
                                 INT  Confidence,
                                 INT  NumberOfBytes,
                                 CHAR *Value,
                                 STRING *Reference,
                                 STRING *Text);

extern CHAR *GetNameGenPropValue(GenPropValue *str);
extern INT  GetIDGenPropValue(GenPropValue *str);
extern void PrintGenPropValue(GenPropValue *eleptr);
extern void FreeGenPropValue(GenPropValue *eleptr);
extern void *AllocGenPropValue();
extern void WriteBinGenPropValue(GenPropValue *eleptr, DbaseLinkedList *file);
extern INT ReadBinGenPropValue(GenPropValue *eleptr, DbaseLinkedList *file);
extern void xdr_GenPropValue(XDR *stream, char **eleptr);
extern void CopyFullGenPropValue(GenPropValue *newstruct, GenPropValue *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:101:PropertyValues

     NumberOfAllocatedValues --(INT) The number of Allocated Values
           NumberOfValues --(INT) The number of different values for this property
                   Values --(GenPropValue) The set of property values
                     Type --(INT) The property type (refering to the PropertyType structure)
                     Text --(STRING) A string text explanation of the property
*/
typedef struct propertyvalues PropertyValues;
struct propertyvalues {
     INT ID;
     CHAR *Name;
     INT  NumberOfAllocatedValues;
     INT  NumberOfValues;
     GenPropValue *Values;
     INT  Type;
     STRING *Text;
     };
#define PropertyValuesSize sizeof(PropertyValues)
#define AllocatePropertyValues (PropertyValues *) Malloc(PropertyValuesSize)
#define AllocArrayPropertyValues(n) (PropertyValues *) Calloc(n,PropertyValuesSize)
#define PropertyValuesPntrSize sizeof(PropertyValues **)
#define AllocPntrArrayPropertyValues(n) (PropertyValues **) Calloc(n,PropertyValuesPntrSize)
#define SingCopyPropertyValues(out,in) memcpy(out,in,PropertyValuesSize)
extern PropertyValues *CreatePropertyValues(PropertyValues *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfAllocatedValues,
                                     INT  NumberOfValues,
                                     GenPropValue *Values,
                                     INT  Type,
                                     STRING *Text);

extern CHAR *GetNamePropertyValues(PropertyValues *str);
extern INT  GetIDPropertyValues(PropertyValues *str);
extern void PrintPropertyValues(PropertyValues *eleptr);
extern void FreePropertyValues(PropertyValues *eleptr);
extern void *AllocPropertyValues();
extern void WriteBinPropertyValues(PropertyValues *eleptr, DbaseLinkedList *file);
extern INT ReadBinPropertyValues(PropertyValues *eleptr, DbaseLinkedList *file);
extern void xdr_PropertyValues(XDR *stream, char **eleptr);
extern void CopyFullPropertyValues(PropertyValues *newstruct, PropertyValues *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:103:SetOfPropertyValues

       NumberOfProperties --(INT) The number of property values stored.
               Properties --(PropertyValues) The set of property values
*/
typedef struct setofpropertyvalues SetOfPropertyValues;
struct setofpropertyvalues {
     INT ID;
     CHAR *Name;
     INT  NumberOfProperties;
     PropertyValues *Properties;
     };
#define SetOfPropertyValuesSize sizeof(SetOfPropertyValues)
#define AllocateSetOfPropertyValues (SetOfPropertyValues *) Malloc(SetOfPropertyValuesSize)
#define AllocArraySetOfPropertyValues(n) (SetOfPropertyValues *) Calloc(n,SetOfPropertyValuesSize)
#define SetOfPropertyValuesPntrSize sizeof(SetOfPropertyValues **)
#define AllocPntrArraySetOfPropertyValues(n) (SetOfPropertyValues **) Calloc(n,SetOfPropertyValuesPntrSize)
#define SingCopySetOfPropertyValues(out,in) memcpy(out,in,SetOfPropertyValuesSize)
extern SetOfPropertyValues *CreateSetOfPropertyValues(SetOfPropertyValues *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfProperties,
                                               PropertyValues *Properties);

extern CHAR *GetNameSetOfPropertyValues(SetOfPropertyValues *str);
extern INT  GetIDSetOfPropertyValues(SetOfPropertyValues *str);
extern void PrintSetOfPropertyValues(SetOfPropertyValues *eleptr);
extern void FreeSetOfPropertyValues(SetOfPropertyValues *eleptr);
extern void *AllocSetOfPropertyValues();
extern void WriteBinSetOfPropertyValues(SetOfPropertyValues *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfPropertyValues(SetOfPropertyValues *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfPropertyValues(XDR *stream, char **eleptr);
extern void CopyFullSetOfPropertyValues(SetOfPropertyValues *newstruct, SetOfPropertyValues *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:105:PropertyType

           CalculateValue --(FUNCTION) The default function to calculate the property value
                FreeValue --(FUNCTION) Free the data structure
             ReadBinValue --(FUNCTION) To translate the value from bytes
            WriteBinValue --(FUNCTION) To translate the value into bytes
          TranslateString --(FUNCTION) Translate a ASCII version to the value
         PrintSingleValue --(FUNCTION) Print out the property value
              ValueOnLine --(FUNCTION) Print out the property value on one line
       MinimumFieldLength --(INT) The minimum size of the one line field
                     Text --(STRING) A text string explaining property
*/
typedef struct propertytype PropertyType;
struct propertytype {
     INT ID;
     CHAR *Name;
     GenPropValue *(*CalculateValue)();
     void  (*FreeValue)();
     INT  (*ReadBinValue)();
     void  (*WriteBinValue)();
     void  (*TranslateString)();
     void  (*PrintSingleValue)();
     CHAR *(*ValueOnLine)();
     INT  MinimumFieldLength;
     STRING *Text;
     };
#define PropertyTypeSize sizeof(PropertyType)
#define AllocatePropertyType (PropertyType *) Malloc(PropertyTypeSize)
#define AllocArrayPropertyType(n) (PropertyType *) Calloc(n,PropertyTypeSize)
#define PropertyTypePntrSize sizeof(PropertyType **)
#define AllocPntrArrayPropertyType(n) (PropertyType **) Calloc(n,PropertyTypePntrSize)
#define SingCopyPropertyType(out,in) memcpy(out,in,PropertyTypeSize)
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
                                 STRING *Text);

extern CHAR *GetNamePropertyType(PropertyType *str);
extern INT  GetIDPropertyType(PropertyType *str);
extern void PrintPropertyType(PropertyType *eleptr);
extern void FreePropertyType(PropertyType *eleptr);
extern void *AllocPropertyType();
extern void WriteBinPropertyType(PropertyType *eleptr, DbaseLinkedList *file);
extern INT ReadBinPropertyType(PropertyType *eleptr, DbaseLinkedList *file);
extern void xdr_PropertyType(XDR *stream, char **eleptr);
extern void CopyFullPropertyType(PropertyType *newstruct, PropertyType *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:106:SetOfPropertyTypes

     NumberOfPropertyTypes --(INT) The number of property types specified
                    Types --(PropertyType) The set of property types
*/
typedef struct setofpropertytypes SetOfPropertyTypes;
struct setofpropertytypes {
     INT ID;
     CHAR *Name;
     INT  NumberOfPropertyTypes;
     PropertyType *Types;
     };
#define SetOfPropertyTypesSize sizeof(SetOfPropertyTypes)
#define AllocateSetOfPropertyTypes (SetOfPropertyTypes *) Malloc(SetOfPropertyTypesSize)
#define AllocArraySetOfPropertyTypes(n) (SetOfPropertyTypes *) Calloc(n,SetOfPropertyTypesSize)
#define SetOfPropertyTypesPntrSize sizeof(SetOfPropertyTypes **)
#define AllocPntrArraySetOfPropertyTypes(n) (SetOfPropertyTypes **) Calloc(n,SetOfPropertyTypesPntrSize)
#define SingCopySetOfPropertyTypes(out,in) memcpy(out,in,SetOfPropertyTypesSize)
extern SetOfPropertyTypes *CreateSetOfPropertyTypes(SetOfPropertyTypes *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfPropertyTypes,
                                             PropertyType *Types);

extern CHAR *GetNameSetOfPropertyTypes(SetOfPropertyTypes *str);
extern INT  GetIDSetOfPropertyTypes(SetOfPropertyTypes *str);
extern void PrintSetOfPropertyTypes(SetOfPropertyTypes *eleptr);
extern void FreeSetOfPropertyTypes(SetOfPropertyTypes *eleptr);
extern void *AllocSetOfPropertyTypes();
extern void WriteBinSetOfPropertyTypes(SetOfPropertyTypes *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfPropertyTypes(SetOfPropertyTypes *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfPropertyTypes(XDR *stream, char **eleptr);
extern void CopyFullSetOfPropertyTypes(SetOfPropertyTypes *newstruct, SetOfPropertyTypes *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:108:ValueTypeIntVector

           NumberOfValues --(INT) The number of values in the vector
                   Values --(INT) The set of integer values
*/
typedef struct valuetypeintvector ValueTypeIntVector;
struct valuetypeintvector {
     INT ID;
     CHAR *Name;
     INT  NumberOfValues;
     INT *Values;
     };
#define ValueTypeIntVectorSize sizeof(ValueTypeIntVector)
#define AllocateValueTypeIntVector (ValueTypeIntVector *) Malloc(ValueTypeIntVectorSize)
#define AllocArrayValueTypeIntVector(n) (ValueTypeIntVector *) Calloc(n,ValueTypeIntVectorSize)
#define ValueTypeIntVectorPntrSize sizeof(ValueTypeIntVector **)
#define AllocPntrArrayValueTypeIntVector(n) (ValueTypeIntVector **) Calloc(n,ValueTypeIntVectorPntrSize)
#define SingCopyValueTypeIntVector(out,in) memcpy(out,in,ValueTypeIntVectorSize)
extern ValueTypeIntVector *CreateValueTypeIntVector(ValueTypeIntVector *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfValues,
                                             INT *Values);

extern CHAR *GetNameValueTypeIntVector(ValueTypeIntVector *str);
extern INT  GetIDValueTypeIntVector(ValueTypeIntVector *str);
extern void PrintValueTypeIntVector(ValueTypeIntVector *eleptr);
extern void FreeValueTypeIntVector(ValueTypeIntVector *eleptr);
extern void *AllocValueTypeIntVector();
extern void WriteBinValueTypeIntVector(ValueTypeIntVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinValueTypeIntVector(ValueTypeIntVector *eleptr, DbaseLinkedList *file);
extern void xdr_ValueTypeIntVector(XDR *stream, char **eleptr);
extern void CopyFullValueTypeIntVector(ValueTypeIntVector *newstruct, ValueTypeIntVector *oldstruct);
/*------------------------------------------*/
/*   Structures for storing properties   */
/* Structure:108:ValueTypeFltVector

           NumberOfValues --(INT) The number of values in the vector
                   Values --(FLOAT) The set of integer values
*/
typedef struct valuetypeFltvector ValueTypeFltVector;
struct valuetypeFltvector {
     INT ID;
     CHAR *Name;
     INT  NumberOfValues;
     FLOAT *Values;
     };
#define ValueTypeFltVectorSize sizeof(ValueTypeFltVector)
#define AllocateValueTypeFltVector (ValueTypeFltVector *) Malloc(ValueTypeFltVectorSize)
#define AllocArrayValueTypeFltVector(n) (ValueTypeFltVector *) Calloc(n,ValueTypeFltVectorSize)
#define ValueTypeFltVectorPntrSize sizeof(ValueTypeFltVector **)
#define AllocPntrArrayValueTypeFltVector(n) (ValueTypeFltVector **) Calloc(n,ValueTypeFltVectorPntrSize)
#define SingCopyValueTypeFltVector(out,in) memcpy(out,in,ValueTypeFltVectorSize)
extern ValueTypeFltVector *CreateValueTypeFltVector(ValueTypeFltVector *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfValues,
                                             FLOAT *Values);

extern CHAR *GetNameValueTypeFltVector(ValueTypeFltVector *str);
extern INT  GetIDValueTypeFltVector(ValueTypeFltVector *str);
extern void PrintValueTypeFltVector(ValueTypeFltVector *eleptr);
extern void FreeValueTypeFltVector(ValueTypeFltVector *eleptr);
extern void *AllocValueTypeFltVector();
extern void WriteBinValueTypeFltVector(ValueTypeFltVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinValueTypeFltVector(ValueTypeFltVector *eleptr, DbaseLinkedList *file);
extern void xdr_ValueTypeFltVector(XDR *stream, char **eleptr);
extern void CopyFullValueTypeFltVector(ValueTypeFltVector *newstruct, ValueTypeFltVector *oldstruct);
