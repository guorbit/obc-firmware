with Text_IO; use Text_IO;

with ASN1_Ada_Iterators.Iterators;         use ASN1_Ada_Iterators.Iterators;

package body Tm_Collection_Events is

   procedure Process_Event
     (Event        : asn1sccObservable_Event;
      Global_State : in out asn1SccSystem_State)
   is
      Evt : constant asn1sccTm_Collection_Event :=
              (case Event.Kind is
                 when Input_Event_Present =>
                    Event.Input_Event.Event.Tm_Collection,
                 when Output_Event_Present =>
                    Event.Output_Event.Event.Tm_Collection,
                 when others => asn1sccTm_Collection_Event_Init);
      --  To transform outputs into a corresponding input message to place
      --  in the recipient queue (with a possibly different name):
      Input_Event : asn1SccObservable_Event (Kind => Input_Event_PRESENT);
   begin
      -- This function executes provided interface events only
      if Event.Kind in No_Event_Present .. System_Startup_Present then
         return;
      end if;
   end Process_Event;

   procedure Print_Event (Event : asn1sccTm_Collection_Event) is
   begin
      null;
   end Print_Event;



end Tm_Collection_Events;
