with Simulation_Dataview;  use Simulation_Dataview;

package Simulator is

   --  To add an event to the system FIFO (e.g. when functions call a RI)
   procedure Push_Event (Event : asn1SccObservable_Event);

   --  Get the first stored event from the FIFO
   function Pop_Event return asn1SccObservable_Event;

   --  Exception raised by Pop_Event if the FIFO is empty
   Empty_Queue : exception;

   --  System-level list of events, filled when user calls a RI.
   Events : aliased asn1SccEvents_Ty := asn1SccEvents_Ty_Init;

end Simulator;
