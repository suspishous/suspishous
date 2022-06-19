#![feature(prelude_import)]
#![feature(fmt_internals)]
#![no_main]

#[prelude_import]
use ::std::prelude::rust_2021::*;

#[macro_use]
extern crate std;
#[macro_use]
extern crate alloc;

extern crate libc;

// NEEDED TO ENSURE THAT IT WILL WORK IF SOME SUSPISHOUS PEOPLE NAMED A VARIABLE "std"
use ::std::cell::{Cell, RefCell};
use ::std::rc::Rc;
use ::std::sync::Arc;

struct Sus {
    is_sus: ::core::primitive::bool,
    how_sus: ::core::primitive::u128,
    is_very_sus: Rc<RefCell<Cell<Arc<Box<::core::primitive::bool>>>>>,
    amog: *const ::core::primitive::bool,
}

impl Default for Sus {
    fn default() -> Self {
        Self {
            is_sus: 1 == 1,
            how_sus: ::std::u128::MAX,
            is_very_sus: ::std::rc::Rc::new(RefCell::new(Cell::new(Arc::new(Box::new(true))))),
            amog: ::alloc::vec::from_elem(true, 128).as_ptr(),
        }
    }
}

#[no_mangle]
pub extern "C" fn main(_argc: ::core::primitive::isize,
    _argv: *const *const ::core::primitive::u8) -> ::core::primitive::isize {
    let sussy = Sus::default();
    const SUSPISHOUS: &'static ::core::primitive::str =
        "suspishous?!?!?!?!?!?!!!!\n\0";
        
    unsafe { libc::printf(SUSPISHOUS.as_ptr() as *const _); }
    let sus =
        {
            let res =
                ::alloc::fmt::format(::core::fmt::Arguments::new_v1(&["Is sus: ",
                                    "\nHow sus: ", "\n\u{0}"],
                        &[::core::fmt::ArgumentV1::new_display(&sussy.is_sus),
                                    ::core::fmt::ArgumentV1::new_display(&sussy.how_sus)]));
            res
        };
    unsafe { libc::printf(sus.as_str().as_ptr() as *const _); }
    drop(sussy.is_very_sus);
    unsafe { drop(*sussy.amog); }
    0
}
