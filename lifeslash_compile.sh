linuxHex="ergodox_ez_base_lifeslash_linux.hex"
winHex="ergodox_ez_base_lifeslash_win.hex"
macHex="ergodox_ez_base_lifeslash_mac_ja.hex"

if [ -e $linuxHex ]; then
    rm $linuxHex
fi
if [ -e $winHex ]; then
    rm $winHex
fi
if [ -e $macHex ]; then
    rm $macHex
fi
qmk compile -kb ergodox_ez -km lifeslash_linux
qmk compile -kb ergodox_ez -km lifeslash_win
#qmk compile -kb ergodox_ez -km lifeslash_mac_ja
