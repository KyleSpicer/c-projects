#!/bin/bash
for f in *.csv
do
        pcap="../${f%.csv}.pcap"
        echo "${pcap}"
        ../../generator/generator $f $pcap df290c80bb7f9ecb08d4a6b3030951aa
done
