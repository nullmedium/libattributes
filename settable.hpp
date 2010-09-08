#ifndef SETTABLE_HPP
#define SETTABLE_HPP

#include <map>
#include <string>

#include <boost/shared_ptr.hpp>

namespace settable {
    namespace setter {
        namespace string2type {
            namespace helper {
                template <typename T>
                T convert(const std::string &value);
            }
        }

        class abstract_setter {
        public:
            virtual void operator=(const std::string &value) = 0;
        };

        template <typename T>
        class setter : public abstract_setter {
        public:
            setter(void *p) : ptr(p) {
                BOOST_ASSERT(ptr != 0);
            }
            
            virtual void operator=(const std::string &value) {
                T *ptrT = static_cast<T*>(ptr);
                BOOST_ASSERT(ptrT != 0);

                *ptrT = string2type::helper::convert<T>(value);
            }

            void *ptr;
        };
    }

    class settable {
    public:
        void set_attribute(const std::string &attr, const std::string &value) {
            boost::shared_ptr<setter::abstract_setter> setter = setters[attr];
            
            if (setter) {
                *setter = value;
            }
        }

        template <typename T>
        void register_setter(const std::string &name, void *ptr) {
            setters.insert(std::make_pair(name, boost::shared_ptr<setter::abstract_setter>(new setter::setter<T>(ptr))));
        }

    private:
        std::map< std::string, boost::shared_ptr<setter::abstract_setter> > setters;
    };
}

#endif /* SETTABLE_HPP */

