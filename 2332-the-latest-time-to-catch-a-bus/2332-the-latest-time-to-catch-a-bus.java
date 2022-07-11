class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        
        Arrays.sort(buses);
        Arrays.sort(passengers);
        
        // मेरे आने का समय 
        int myArrivalTime = 1;
        
        // पहला यात्री 
        int currentPassenger = 0;
        
        // पहले से पीछे वाला यात्री 
        int prevPassenger = -1;
        
        // कुल यात्री 
        int totalPassengers = passengers.length;
        
        // हर बस को चेक करेंगे 
        for(int bus=0; bus<buses.length; bus++){
            
            // अभी बस में यात्रियों की संख्या 
            int currentCapacity = 0;
            // बस की रवानगी का समय 
            int currentBusDeparture = buses[bus];
            
            // अब हम यहाँ तीन चीजे चेक करेंगे 
            // बस फुल तो नहीं है && अभी पैसेंजर बचे हुए है && पैसेंजर बस के निकलने तक पहुंच गया है
            while(currentCapacity<capacity && currentPassenger<totalPassengers && passengers[currentPassenger]<=currentBusDeparture){
                
                // जो पैसेंजर आया है और अगर उससे एक मिनट पहले कोई और पैसेंजर नहीं आया है तो मैं उससे एक मिनट पहले आ जाऊंगा, ताकि मुझे सीट मिल जाये 
                if(passengers[currentPassenger]-1!=prevPassenger){
                    myArrivalTime = passengers[currentPassenger]-1;
                }
                
                // अब मैं अभी के पैसेंजर को पिछले पैसेंजर में स्टोर कर देता हू
                prevPassenger = passengers[currentPassenger];
                
                currentCapacity++;
                currentPassenger++;
            }
            
            // अब मैं देखूंगा, की बस में जगह फुल नहीं हुई, और जो लास्ट पैसेंजर बैठा है क्या उसका समय बस के जाने के समय पर नहीं है,               
            // तो मैं बस के जाने के समय ही आऊंगा
            if(currentCapacity<capacity && currentBusDeparture!=prevPassenger){
                myArrivalTime = currentBusDeparture;
            }
            
        }
        
        //मेरे जाने का समय बता दो अब :)
        return myArrivalTime;
    }
}