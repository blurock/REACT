/*------------------------------------------*/
/*   ASCII Property Structures   */
/* Structure:1:ASCIIProperty

            PropertyValue --(STRING) The property value
*/
typedef struct asciiproperty ASCIIProperty;
struct asciiproperty {
     INT ID;
     CHAR *Name;
     STRING *PropertyValue;
     };
#define ASCIIPropertySize sizeof(ASCIIProperty)
#define AllocateASCIIProperty (ASCIIProperty *) Malloc(ASCIIPropertySize)
#define AllocArrayASCIIProperty(n) (ASCIIProperty *) Calloc(n,ASCIIPropertySize)
#define ASCIIPropertyPntrSize sizeof(ASCIIProperty **)
#define AllocPntrArrayASCIIProperty(n) (ASCIIProperty **) Calloc(n,ASCIIPropertyPntrSize)
#define SingCopyASCIIProperty(out,in) memcpy(out,in,ASCIIPropertySize)
extern ASCIIProperty *CreateASCIIProperty(ASCIIProperty *newstruct,
                                   INT id,
                                   CHAR *name,
                                   STRING *PropertyValue);

extern CHAR *GetNameASCIIProperty(ASCIIProperty *str);
extern INT  GetIDASCIIProperty(ASCIIProperty *str);
extern void PrintASCIIProperty(ASCIIProperty *eleptr);
extern void FreeASCIIProperty(ASCIIProperty *eleptr);
extern void *AllocASCIIProperty();
extern void WriteBinASCIIProperty(ASCIIProperty *eleptr, DbaseLinkedList *file);
extern INT ReadBinASCIIProperty(ASCIIProperty *eleptr, DbaseLinkedList *file);
extern void xdr_ASCIIProperty(XDR *stream, char **eleptr);
extern void CopyFullASCIIProperty(ASCIIProperty *newstruct, ASCIIProperty *oldstruct);
/*------------------------------------------*/
/*   ASCII Property Structures   */
/* Structure:2:ASCIIProperties

       NumberOfProperties --(INT) The number of properties listed
               Properties --(ASCIIProperty) The set of propertties (as ASCII text)
*/
typedef struct asciiproperties ASCIIProperties;
struct asciiproperties {
     INT ID;
     CHAR *Name;
     INT  NumberOfProperties;
     ASCIIProperty *Properties;
     };
#define ASCIIPropertiesSize sizeof(ASCIIProperties)
#define AllocateASCIIProperties (ASCIIProperties *) Malloc(ASCIIPropertiesSize)
#define AllocArrayASCIIProperties(n) (ASCIIProperties *) Calloc(n,ASCIIPropertiesSize)
#define ASCIIPropertiesPntrSize sizeof(ASCIIProperties **)
#define AllocPntrArrayASCIIProperties(n) (ASCIIProperties **) Calloc(n,ASCIIPropertiesPntrSize)
#define SingCopyASCIIProperties(out,in) memcpy(out,in,ASCIIPropertiesSize)
extern ASCIIProperties *CreateASCIIProperties(ASCIIProperties *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfProperties,
                                       ASCIIProperty *Properties);

extern CHAR *GetNameASCIIProperties(ASCIIProperties *str);
extern INT  GetIDASCIIProperties(ASCIIProperties *str);
extern void PrintASCIIProperties(ASCIIProperties *eleptr);
extern void FreeASCIIProperties(ASCIIProperties *eleptr);
extern void *AllocASCIIProperties();
extern void WriteBinASCIIProperties(ASCIIProperties *eleptr, DbaseLinkedList *file);
extern INT ReadBinASCIIProperties(ASCIIProperties *eleptr, DbaseLinkedList *file);
extern void xdr_ASCIIProperties(XDR *stream, char **eleptr);
extern void CopyFullASCIIProperties(ASCIIProperties *newstruct, ASCIIProperties *oldstruct);
