linuxHex="ergodox_ez_base_lifeslash_linux.hex"
winHex="ergodox_ez_base_lifeslash_win.hex"
eucalynHex="ergodox_ez_base_lifeslash_eucalyn.hex"

if [ -e $linuxHex ]; then
    rm $linuxHex
fi
if [ -e $winHex ]; then
    rm $winHex
fi
if [ -e $eucalynHex ]; then
    rm $eucalynHex
fi

qmk compile -kb ergodox_ez -km lifeslash_linux
qmk compile -kb ergodox_ez -km lifeslash_win
qmk compile -kb ergodox_ez -km lifeslash_eucalyn
