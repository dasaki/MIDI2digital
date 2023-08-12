# MIDI2digital
Uses Arduino's MIDIusb library to control digital pins with midi signals

Midi notes received by the Arduino board are mapped to pins' HIGH/LOW status:

| HEX_NOTE | TONE | PIN | STATUS |
| :-----------: |  :-----------: | :-----------: | :-----------: |
| 0x30 | C 3 | A0 | LOW |
| 0x31 | C# 3 | A0 | HIGH |
| 0x32 | D 3| A1 | LOW |
| 0x33 | D# 3 | A1 | HIGH |
| 0x35 | F 3 | A2 | LOW |
| 0x36 | F# 3 | A2 | HIGH |
| 0x37 | G 3 | A3 | LOW |
| 0x38 | G# 3 | A3 | HIGH |
| 0x39 | A 3 | 2 | LOW |
| 0x3A | A# 3 | 2 | HIGH |
| 0x3C | C 4 | 3 | LOW |
| 0x3D | C# 4 | 3 | HIGH |
| 0x3E | D 4 | 4 | LOW |
| 0x3F | D# 4 | 4 | HIGH |
| 0x41 | F 4 | 5 | LOW |
| 0x42 | F# 4 | 5 | HIGH |
| 0x43 | G 4 | 6 | LOW |
| 0x44 | G# 4 | 6 | HIGH |
| 0x45 | A 4 | 7 | LOW |
| 0x46 | A# 4 | 7 | HIGH |
| 0x48 | C 5 | 8 | LOW |
| 0x49 | C# 5 | 8 | HIGH |
| 0x4A | D 5 | 9 | LOW |
| 0x4B | D# 5 | 9 | HIGH |
| 0x4D | F 5 | 10 | LOW |
| 0x4E | F# 5 | 10 | HIGH |
| 0x4F | G 5 | 11 | LOW |
| 0x50 | G# 5 | 11 | HIGH |
| 0x51 | A 5 | 12 | LOW |
| 0x52 | A# 5 | 12 | HIGH |
| 0x54 | C 6 | 13 | LOW |
| 0x55 | C# 6 | 13 | HIGH |

