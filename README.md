# MIDI2digital
Uses Arduino's MIDIusb library to control digital pins with midi signals

Midi notes received by the Arduino board are mapped to pins' HIGH/LOW status:

| NOTE_# | NOTE_NAME | PIN | STATUS |
| 0x30 | C | A0 | LOW |

0x31&nbsp;&nbsp;&nbsp;&nbsp;C#&nbsp;&nbsp;&nbsp;&nbsp;A0&nbsp;&nbsp;&nbsp;&nbsp;HIGH

0x32&nbsp;&nbsp;&nbsp;&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;A1&nbsp;&nbsp;&nbsp;&nbsp;LOW

0x33&nbsp;&nbsp;&nbsp;&nbsp;D#&nbsp;&nbsp;&nbsp;&nbsp;A1&nbsp;&nbsp;&nbsp;&nbsp;HIGH


  // #3 -> A2
  {0x35, A2, LOW},
  {0x36, A2, HIGH},
  // #4 -> A3
  {0x37, A3, LOW},
  {0x38, A3, HIGH},
  // #5 -> D2
  {0x39, 2, LOW},
  {0x3A, 2, HIGH},
  // #6 -> D3
  {0x3C, 3, LOW},
  {0x3D, 3, HIGH},
  // #7 -> D4
  {0x3E, 4, LOW},
  {0x3F, 4, HIGH},
  // #8 -> D5
  {0x41, 5, LOW},
  {0x42, 5, HIGH},
  // #9 -> D6
  {0x43, 6, LOW},
  {0x44, 6, HIGH},
  // #10 -> D7
  {0x45, 7, LOW},
  {0x46, 7, HIGH},
  // #11 -> D8
  {0x48, 8, LOW},
  {0x49, 8, HIGH},
  // #12 -> D9
  {0x4A, 9, LOW},
  {0x4B, 9, HIGH},
  // #13 -> D10
  {0x4D, 10, LOW},
  {0x4E, 10, HIGH},
  // #14 -> D11
  {0x4F, 11, LOW},
  {0x50, 11, HIGH},
  // #15 -> D12
  {0x51, 12, LOW},
  {0x52, 12, HIGH},
  // #16 -> D13
  {0x54, 13, LOW},
  {0x55, 13, HIGH}
