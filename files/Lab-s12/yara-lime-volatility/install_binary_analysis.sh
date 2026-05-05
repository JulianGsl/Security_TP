sudo dpkg -i libdwarf1_20191104-1_i386.deb dwarfdump_20191104-1_i386.deb libyara4_4.0.5-1_i386.deb yara_4.0.5-1_i386.deb
python get-pip2.py; python -m pip install yara-python==4.2.3
python3 get-pip.py;

git clone https://github.com/504ensicsLabs/LiME.git
cd LiME/src
make
cd ../..

git clone https://github.com/volatilityfoundation/volatility.git
cd volatility/tools/linux
make
cd ../..
sudo zip ./volatility/plugins/overlays/linux/Kali-5.3.0-686.zip ./tools/linux/module.dwarf /boot/System.map-5.3.0-kali2-686-pae