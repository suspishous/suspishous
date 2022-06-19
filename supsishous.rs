#![no_main]

extern crate libc;

// NEEDED TO ENSURE THAT IT WILL WORK IF SOME SUSPISHOUS PEOPLE NAMED A VARIABLE "std"
use ::std::cell::{Cell, RefCell};
use ::std::rc::Rc;
use ::std::sync::Arc;

struct Sus {
    is_sus: bool,
    how_sus: u128,
    is_very_sus: Rc<RefCell<Cell<Arc<Box<bool>>>>>,
    amog: *const bool,
}

impl Default for Sus {
    fn default() -> Self {
        Self {
            is_sus: true,
            how_sus: ::std::u128::MAX,
            is_very_sus: Rc::new(RefCell::new(Cell::new(Arc::new(Box::new(true))))),
            amog: vec![true; 128].as_ptr(),
        }
    }
}

#[no_mangle]
pub extern "C" fn main(_argc: isize, _argv: *const *const u8) -> isize {
    let sussy = Sus::default();

    const SUSPISHOUS: &str = "suspishous?!?!?!?!?!?!!!!\n\0";
    unsafe {
        libc::printf(SUSPISHOUS.as_ptr() as *const _);
    }

    let sus = format!("Is sus: {}\nHow sus: {}\n\0", sussy.is_sus, sussy.how_sus);
    unsafe {
        libc::printf(sus.as_str().as_ptr() as *const _);
    }

    drop(sussy.is_very_sus);

    unsafe {
        drop(*sussy.amog);
    }
    0
}
