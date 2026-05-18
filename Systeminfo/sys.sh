while true ; do
clear
mem_total=$(awk '/MemTotal/ {printf "%.2f", $2/1048576}' /proc/meminfo)
mem_free=$(awk '/MemFree/ {printf "%.2f", $2/1048576}' /proc/meminfo)
mem_available=$(awk '/MemAvailable/ {printf "%.2f", $2/1048576}' /proc/meminfo)
cpu_model=$(awk -F ':' '/model name/ && !seen[$1]++ {print $2}' /proc/cpuinfo)
 

echo "RAM Total: ${mem_total} GB"
echo "RAM Free: ${mem_free} GB" 
echo "RAM Available: ${mem_available} GB"
echo "CPU Model: ${cpu_model}" 
echo "Your Laptop is on from $(awk '{printf "%.2f", $1/60}' /proc/uptime ) minutes " 

(cat /proc/stat | head -1  ; sleep 0.1 ; cat /proc/stat | head -1 ) | awk '/cpu/ {
      tot=$2+$3+$4+$5+$6+$7+$8+$9+$10; id=$5; 
      if(prev_tot){
        diff_tot = tot - prev_tot;
        diff_id = id - prev_id;

         free = (diff_id/diff_tot)*100;
          used = 100 - free;
         
         printf "CPU FREE: %.1f%% | CPU USED: %.1f%%\n" , free, used 
   
  }
 
 prev_tot = tot;
prev_id = id;
}' 
sleep 0.5
done
 
