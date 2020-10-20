Using the telegraph example, and the challenges listed in the book, describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

I heard once about a program the UW was doing to put seismic sensors in various places around Washington State to get better data about earthquakes.  I would expect it to have the seismic sensor, wifi, a battery with a long life or somehow be rechargeable like solar, have geolocation information, and have a clock.  I would expect it to be in sleep mode unless the seismic sensor is activated at which point it would time the duration and changing magnitude of the seismic event.  Once the seismic activity went down to zero, I would expect it to wirelessly transmit the event back to some external location.  If another seismic event started as it was transmitting the first, I would expect it to be able to record the second as well without the transmission of the first getting in the way.  

Design Challenges not mentioned above:  
Response:  It would need to measure all seismic events in real time.  
Memory space: if there were several seismic events in a very short time span it could run out of space.  Or similarly with a very long seismic event.  
Power consumption:  it should be using almost no power during non seismic events.  
Security:  if someone found the sensor they could create invalid data.  Perhaps the device could transmit a message if the geo location starts to change by a certain amount.  
Reliability: No human intervention once deployed.  
Testability:  Can only test via the wireless notifications it sends out or by being connected to a host machine.  
Debuggability:  No screen or keyboard.  
Cost:  low cost is preferred

