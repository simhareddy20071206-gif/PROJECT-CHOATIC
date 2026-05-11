mem_total=$(awk '/MemTotal/ {printf "%.2f", $2/1048576}' /proc/meminfo)
mem_free=$(awk '/MemFree/ {printf "%.2f", $2/1048576}' /proc/meminfo)
mem_available=$(awk '/MemAvailable/ {printf "%.2f", $2/1048576}' /proc/meminfo)
cpu_model=$(awk -F ':' '/model name/ && !seen[$1]++ {print $2}' /proc/cpuinfo)


echo "RAM Total: ${mem_total} GB" > info.txt
echo "RAM Free: ${mem_free} GB" >> info.txt
echo "RAM Available: ${mem_available} GB" >> info.txt
echo "CPU Model: ${cpu_model}" >>info.txt
echo "Your Laptop is on from $(awk '{printf "%.2f", $1/60}' /proc/uptime ) minutes " >>info.txt
