/**
 * Constants related to the protocol we're using.
 * The protocol packet will have 29 bytes:
 * | Packet number      4 bytes
 * | Reservoir id       1 byte
 * | Water Level value  4 bytes
 * | VCC value          4 bytes
 * | Conductivity value 4 bytes
 * | Salinity value     4 bytes
 * | TDS value          4 bytes
 * | pH value           4 bytes
 * */



// lengths represent bytes
#define PACKET_LEN 29
#define PACKET_NO_FIELD_LEN 4
#define RESERVOIR_ID_FIELD_LEN 1
#define WATER_LEVEL_FIELD_LEN 4
#define VCC_FIELD_LEN 4
#define CONDUCTIVITY_FIELD_LEN 4
#define SALINITY_FIELD_LEN 4
#define TDS_FIELD_LEN 4
#define PH_FIELD_LEN 4

// should be changed according to the reservoir
#define THIS_RESERVOIR_ID 1
