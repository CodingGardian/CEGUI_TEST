#ifndef EVENTS_H
#define EVENTS_H

#include <abstraction/Xlibinterface.h>

/*#include <unistd.h>
#include <assert.h>
#include <string>
#include <initializer_list>
#include <map>
#include <thread>
#include <functional>
#include <vector>
#include <list>

#include <memory/memory.h>
//#include <base/function.h>

namespace CEGUI {
    namespace EVENTS {
        
        class EventBase;

        class EventListener;

        class EventEmitter;

        class EventHandler;

        class Endpoint;

        typedef std::shared_ptr<EventListener> CEventListener;
        typedef std::shared_ptr<EventEmitter> CEventEmitter;

        // I'm sorry, but C++ forced my hand ( why no private members in namespaces ლ(·̿̿Ĺ̯̿̿·̿ლ) )
        class EventSys {
        private:
            EventSys();

            // list holds all of the endpoints 
            static std::map<std::string, std::unique_ptr<Endpoint>> m_endpointMap;

            // matches id of emitter to listeners bound to it
            static std::map<EventEmitter, std::list< CEventListener >> m_emitterMap;
            static std::map<std::string, CEventEmitter> m_emitterId;
            //std::map<EventListener, std::list< std::shared_ptr<Endpoint> >> m_listenerMap;
        public:

            // Initalization functions
            static void InitEvent();

            // Get data structures
            static inline void CreateEndpoint(const std::function<const EventBase&()>& func, const std::string& s) {
                Endpoint* e = new Endpoint(func);
                m_endpointMap[s] = std::make_unique<Endpoint>(e);
            }

            static inline const CEventEmitter& CreateEmitter(const std::function<const EventBase&()>& func, const std::string& id) {
                EventEmitter* e = new EventEmitter(func, id);
                m_emitterId[id] = std::make_shared<EventEmitter>(e);
                m_emitterMap[*e];

                return std::make_shared<EventEmitter>(e);
            }

            static inline void BindEmitter(const std::string& id, CEventListener& e) {
                const CEventEmitter& temp = m_emitterId[id];
                m_emitterMap[*(temp.get())].push_back(e);
            }

            // Forward events through class
            static void ForwardEvent(const EventBase& e); // event emitter

            // predefined events to avoid overhead with simple functions

        };

        class Endpoint {
        private:
            std::function<const EventBase&()> m_getFunc;
        public:
            Endpoint(const std::function<const EventBase&()>& getFunc); // getfunction (user defined function) constructs an event based off of unkown type
            ~Endpoint() {}

            const EventBase& operator()() const {
                return m_getFunc();
            }
        };

        class EventBase {
        private:
            //std::string m_eventid; // type of event
            std::string m_data;
        public:
            EventBase(const std::string& data);
            ~EventBase() {}
        };
        
        //template<typename T>
        //using EmitFunc = EventBase(*)(T&);

        class EventEmitter { // Emitters are classes that use user defined functions to pack up the event with the id and data and send it is emitted
        private:
            std::function<const EventBase&()> m_emitfunc;
            std::string m_id;
        public:
            EventEmitter(const std::function<const EventBase&()>& emitfunc, const std::string& id);
            ~EventEmitter();
        
            void operator()() const {
                return EventSys::ForwardEvent(m_emitfunc());
            }

            bool operator==(EventEmitter&& e) const {
                return this->m_id == e.m_id;
            }

            friend class EventSys;
        };
        
        class EventHandler {
        private:
            std::function<void(const EventBase&)> m_handlefunc;
        public:
            EventHandler(std::function<void(const EventBase&)> handlefunc);
            ~EventHandler() {}

            const void operator()(const EventBase& e) const {m_handlefunc(e);}
        };

        class EventListener {
        private:
            std::vector<EventHandler> m_handle;
        public:
            EventListener(const std::initializer_list<EventHandler>& handle);
            ~EventListener();

            const EventBase& Poll();
            const EventBase& PollEndpoint(std::string id);
            void BindEndpoint(std::string id);
            void BindEvent(std::string id);

            void operator()(const EventBase& e) const;

            friend class EventSys;
        };

    };
};*/

namespace CEGUI {
	namespace XINTERFACE {
		namespace EVENT {

		};
	};
};
#endif