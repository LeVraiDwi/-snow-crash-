On trouve un fichier .pcap c'est un fichier qui contient des paquets:
    en l'ouvrant avec wireshack on peut trouver un paquet qui contient le mot pass word:
        en l' inspectant => clique droit => follow => tcp stream:

char peer0_13[] = { /* Packet 45 */
0x66 }; f
char peer0_14[] = { /* Packet 47 */
0x74 }; t
char peer0_15[] = { /* Packet 49 */
0x5f }; _
char peer0_16[] = { /* Packet 51 */
0x77 }; w
char peer0_17[] = { /* Packet 53 */
0x61 }; a
char peer0_18[] = { /* Packet 55 */
0x6e }; n
char peer0_19[] = { /* Packet 57 */
0x64 }; d
char peer0_20[] = { /* Packet 59 */
0x72 }; r
char peer0_21[] = { /* Packet 61 */
0x7f }; del
char peer0_22[] = { /* Packet 63 */
0x7f }; del
char peer0_23[] = { /* Packet 65 */
0x7f }; del
char peer0_24[] = { /* Packet 67 */
0x4e }; N
char peer0_25[] = { /* Packet 69 */
0x44 }; D
char peer0_26[] = { /* Packet 71 */
0x52 }; R
char peer0_27[] = { /* Packet 73 */
0x65 }; e
char peer0_28[] = { /* Packet 75 */
0x6c }; l
char peer0_29[] = { /* Packet 77 */
0x7f }; del
char peer0_30[] = { /* Packet 79 */
0x4c }; L
char peer0_31[] = { /* Packet 81 */
0x30 }; 0
char peer0_32[] = { /* Packet 83 */
0x4c }; L
char peer0_33[] = { /* Packet 85 */
0x0d }; return

on retrouve le mot de passe:
    ft_waNDReL0L